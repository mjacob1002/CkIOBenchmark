-include ~/charm/common.mk
CHARMC=~/charm/bin/charmc $(OPTS)

all: iotest

iotest: iotest.ci iotest.C
	$(CHARMC) iotest.ci -g 
	$(CHARMC) iotest.C -o $@ -module CkIO -tracemode projections -g

test: iotest
	$(call run, ./iotest +p4 4 )

testp: iotest
	$(call run, ./iotest +p$(P) $(P) )

smptest: iotest
	$(call run, ./iotest 4 +p2 ++ppn 2)
	$(call run, ./iotest 4 +p4 ++ppn 2)

clean:
	rm -f *.o *.decl.h *.def.h iotest 

