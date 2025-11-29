#include "hypervisorentry.h"

int __init hypervsior_entry(void)
{

}

int hypervisor_exit(void)
{
        return 0;
}

module_init(hypervisor_entry);
module_exit(hypervisor_exit);