#include "bsig0_32.h"

using std::vector;
using namespace CMSat;

Bsig0_32::Bsig0_32() : Modul(1) {
    inputs.push_back(0);
    output = 32;
}

Bsig0_32::~Bsig0_32() {
}

unsigned Bsig0_32::getAdditionalVarCount() {
    return 32;
}

unsigned Bsig0_32::getClauseCount() {
    return 32 * XOR_CLAUSE_COUNT(4);
}

void Bsig0_32::create(Printer* printer) {
    for (unsigned i = 0; i < 32; i++) {
        vector<Lit> clause;
        clause.push_back(Lit(output + i, true));
        clause.push_back(Lit(inputs[0] + ((i +  2) % 32), true));
        clause.push_back(Lit(inputs[0] + ((i + 13) % 32), true));
        clause.push_back(Lit(inputs[0] + ((i + 22) % 32), true));
        printer->create(true, clause);
    }
}