#include <linux/module.h>   
#include <linux/kernel.h>   
#include <linux/init.h>     
#include <linux/list.h>     
#include <linux/types.h>    
#include <linux/slab.h>     

#define NUM   10


typedef struct birthday {
    
    int day;
    int month;
    int year;
    struct list_head list;

} birthday;

LIST_HEAD(birthday_list);
int birthdayList_init(void) {

    printk(KERN_INFO "Loading Module\n");
    birthday *person;
    int i = 0;
    for(i = 0; i < NUM; i++) {
        person = kmalloc(sizeof(*person), GFP_KERNEL);
        person->day = 2 + i;
        person->month = 1 + i;
        person->year = 1995 + i;
        INIT_LIST_HEAD(&person->list);
        list_add_tail(&person->list, &birthday_list);
    }
    list_for_each_entry(person, &birthday_list, list) {

        printk(KERN_INFO "Birthday: Month %d Day %d Year %d\n", person->month, person->day, person->year);
    }

           return 0;
}

void birthdayList_exit(void) {

    printk(KERN_INFO "Removing Module\n");
    birthday *ptr, *next;
    list_for_each_entry_safe(ptr, next, &birthday_list, list) {
        list_del(&ptr->list);
        kfree(ptr);
    
    }

    printk(KERN_INFO "sanah oig choloolson\n");

}

module_init(birthdayList_init);
module_exit(birthdayList_exit);
