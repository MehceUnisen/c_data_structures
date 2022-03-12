#include "hm.h"

int main()
{
    hm *main_head = init_hm(20);
    add_data(main_head, 19);
    add_data(main_head, 39);
    add_data(main_head, 59);
    add_data(main_head, 10);
    remove_data(main_head, 59);
    remove_data(main_head, 31);
    print_hm(main_head);
    return 0;
}