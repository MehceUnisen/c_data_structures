#include "hm.h"

int main()
{
    hm *main_head = init_hm(20);
    add_data(main_head, 10);
    add_data(main_head, 30);
    remove_data(main_head, 30);
    // add_data(main_head, 30);

    print_hm(main_head);
    return 0;
}