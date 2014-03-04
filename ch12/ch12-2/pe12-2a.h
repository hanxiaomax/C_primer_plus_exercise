#define METRIC 0
#define US 1

void set_mode(int *pm);//需要通过指针修改mode
void get_info(int mode,double *pd,double *pf);//需要通过指针修改dist和fuel
void show_info(int mode,double dist,double fuel);//只需调用不需要修改