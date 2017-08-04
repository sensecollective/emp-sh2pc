#include "emp-sh2pc/semihonest_gen.h"
#include "emp-sh2pc/semihonest_eva.h"

template<typename IO>
static void setup_semi_honest(IO* io, int party) {
	if(party == ALICE) {
		HalfGateGen<IO> * t = new HalfGateGen<IO>(io);
		CircuitExecution::circ_exec = t;
		ProtocolExecution::prot_exec = new SemiHonestGen<IO>(io, t);
	} else {
		HalfGateEva<IO> * t = new HalfGateEva<IO>(io);
		CircuitExecution::circ_exec = t;
		ProtocolExecution::prot_exec = new SemiHonestEva<IO>(io, t);
	}
}

