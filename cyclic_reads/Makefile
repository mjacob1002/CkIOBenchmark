-include ~/charm/common.mk
CHARMC=~/charm/bin/charmc $(OPTS)

all: cyclic_test 

iotest_gprof: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -pg -g -module CkIO -O3

profile: iotest.ci iotest.C 

	$(CHARMC) iotest.ci -g 
	hpclink $(CHARMC) iotest.C -o $@ -static -module CkIO -tracemode projections -g -O3 # --verbose

iotest.o: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) -c iotest.C -o $@

iotest_summary: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -module CkIO -03 # -tracemode summary -g -O3

iotest: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -module CkIO -tracemode projections -g -O3

cyclic_test.proj: cyclic.C cyclic.ci
	$(CHARMC) cyclic.ci -O3
	$(CHARMC) cyclic.C -o $@ -module CkIO -tracemode projections -O3


cyclic_test: cyclic.C cyclic.ci
	$(CHARMC) cyclic.ci -O3
	$(CHARMC) cyclic.C -o $@ -module CkIO -O3

verification: verify_correctness.C verify_correctness.ci
	$(CHARMC) verify_correctness.ci  -O3
	$(CHARMC) verify_correctness.C -o $@ -module CkIO -O3

test: iotest
	$(call run, ./iotest +p4 4 )

testp: iotest
	$(call run, ./iotest +p$(P) $(P) )

smptest: iotest
	$(call run, ./iotest 4 +p2 ++ppn 2)
	$(call run, ./iotest 4 +p4 ++ppn 2)

clean:
	rm -f *.o *.decl.h *.def.h iotest cyclic_test

