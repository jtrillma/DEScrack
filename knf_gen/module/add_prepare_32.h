#ifndef __ADD_PREPARE_32_H__
#define __ADD_PREPARE_32_H__

#include "modul.h"
#include "../common/minunit.h"

class Add_Prepare_32 : public Modul {
    public:
        Add_Prepare_32();
        ~Add_Prepare_32();

        void create(Printer* printer);
        MU_TEST_H(test);
};

#endif //__ADD_PREPARE_32_H__
