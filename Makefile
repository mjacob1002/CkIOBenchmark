-include ~/charm/benchmark/common.mk
CHARMC=~/charm/bin/charmc $(OPTS)

all: iotest

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
	$(CHARMC) iotest.C -o $@ -module CkIO -tracemode summary -g -O3

iotest: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -module CkIO -g -O3
naive: naive.C naive.ci
	$(CHARMC) naive.ci -g
	$(CHARMC) naive.C -o $@ -g -O3 -tracemode projections -g

iotest.proj: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -module CkIO -tracemode projections -g -O3



test: iotest
	$(call run, ./iotest +p4 4 )

testp: iotest
	$(call run, ./iotest +p$(P) $(P) )

smptest: iotest
	$(call run, ./iotest 4 +p2 ++ppn 2)
	$(call run, ./iotest 4 +p4 ++ppn 2)

clean:
	rm -f *.o *.decl.h *.def.h iotest 

