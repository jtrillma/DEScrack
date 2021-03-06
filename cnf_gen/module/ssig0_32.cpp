#include "ssig0_32.h"

#include "../common/solvertools.h"

using namespace CMSat;

unsigned Ssig0_32::stats[STATS_LENGTH];

Ssig0_32::Ssig0_32() : Modul(32, 1, 1) {
    output = 32;
}

Ssig0_32::~Ssig0_32() {
}

unsigned* Ssig0_32::getStats() {
    return stats;
}

void Ssig0_32::create(Collector* collector) {
    collector->newModul(10, "Ssig0_32", this);

    for (unsigned i = 0; i < 29; i++) {
        createXOR(collector,
                  output + i, 
                  inputs[0] + ((i +  7) % 32),
                  inputs[0] + ((i + 18) % 32),
                  inputs[0] +   i +  3
        );
    }
    for (unsigned i = 29; i < 32; i++) {
        createXOR(collector,
                  output + i, 
                  inputs[0] + ((i +  7) % 32),
                  inputs[0] + ((i + 18) % 32)
        );
    }

#ifdef ADDITIONAL_CLAUSES
    for (unsigned i = 0; i < 1; i++) {
        createXOR(collector, inputs[0] + i, inputs[0] + 10 + i, output + 3 + i, output + 14 + i, output + 31 + i);
    }
    for (unsigned i = 0; i < 2; i++) {
        createXOR(collector, inputs[0] + 8 + i, inputs[0] + 30 + i, output + 1 + i, output + 12 + i, output + 29 + i);
    }
#endif
}

MU_TEST_C(Ssig0_32::test) {
    unsigned a[] = {0xabcdef98};

    for (unsigned t = 0; t < 1; t++) {
        SATSolver solver;
        solver.set_verbosity(0);
        solver.log_to_file("test.log");

        uint32_t ausgabe = (a[t] >> 7 | a[t] << (32-7)) ^ (a[t] >> 18 | a[t] << (32-18)) ^ (a[t] >> 3);

        solver_writeInt(solver, 0, 32, a[t]);

        Ssig0_32 ssig0;
        ssig0.append(&solver);

        lbool ret = solver.solve();
        mu_assert(ret == l_True, "SSIG0 UNSAT");
        mu_assert(ausgabe == solver_readInt(solver, 32, 32), "SSIG0 failed");
    }
}
