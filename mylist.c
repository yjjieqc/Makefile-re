#include<linux/module.h>  
#include<linux/init.h>  
#include<linux/list.h>//包含内核链表头文件  
  
struct score  
{  
    int num;  
    int English;  
    int math;  
    struct list_head list;//链表链接域  
};  
  
struct list_head score_head;//所建立链表的链表头  
  
//定义三个节点 然后插入到链表中  
struct score stu1, stu2, stu3;  
struct list_head *pos;//定义一个结点指针  
struct score *tmp;//定义一个score结构体变量
struct list_head* n;
int find_num = 3;
  
int mylist_init(void)  
{  
    INIT_LIST_HEAD(&score_head);//初始化链表头 完成一个双向循环链表的创建  
      
    stu1.num = 1;  
    stu1.English = 59;  
    stu1.math = 99;  
      
    //然后将三个节点插入到链表中  
    list_add_tail(&(stu1.list), &score_head);//使用尾插法  
      
    stu2.num = 2;  
    stu2.English = 69;  
    stu2.math = 98;  
    list_add_tail(&(stu2.list), &score_head);  
      
    stu3.num = 3;  
    stu3.English = 89;  
    stu3.math = 97;  
    list_add_tail(&(stu3.list), &score_head);  
      
    //遍历整个链表，每次遍历将数据打印出来  
    list_for_each(pos, &score_head)//这里的pos会自动被赋新值  
    {  
        tmp = list_entry(pos, struct score, list); 
	if (tmp->num == find_num)
        printk(KERN_WARNING"num: %d, English: %d, math: %d\n", tmp->num, tmp->English, tmp->math);  
    }  
      
    return 0;  
}  
  
void mylist_exit(void)  
{
	list_for_each_safe(pos, n, &score_head){
	tmp = list_entry(pos, struct score, list);
	printk(KERN_WARNING "delete %d, %d\n", tmp->num, pos->next);
	list_del(&tmp->list);
	printk(KERN_WARNING "delete %d, %d\n", tmp->num, pos->next);
}
} 
  
module_init(mylist_init);  
module_exit(mylist_exit);  
