#ifndef __BSIG0_H__
#define __BSIG0_H__

#include "modul.h"

class Bsig0 : public Modul {
    public:
        Bsig0();
        ~Bsig0();

        unsigned getInputCount();
    protected:
        void create(void (Modul::*createX) (bool, const std::vector<CMSat::Lit>&));
};

#endif //__BSIG0_H__
