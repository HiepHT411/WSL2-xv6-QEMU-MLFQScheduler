#include "types.h"
#include "stat.h"
#include "mmu.h"
#include "param.h"
#include "proc.h"
#include "user.h"
#define NULL ((void *)0)

int
main(int argc, char *argv[])
{
    int tb[100]={0};
  int ctr=0;
  tb[0]=3;

    struct pstat st;

    if(argc != 2){
        printf(1, "usage: mytest counter");
        exit();
    }

    //int i, x, l, j;
    //int mypid = getpid();

    /*for(i = 1; i < atoi(argv[1]); i++){
       x = x + i;
    }*/
    int l, j;
    int mypid = getpid();

    getpinfo(&st);
    
    /*for (j = 0; j < NPROC; j++) {
        if (st.inuse[j] && st.pid[j] >= 2 && st.pid[j] == mypid) {
            for (l = 0; l<4; l++) {
                printf(1, "level:%d \t ticks-used:%d\n", l, st.ticks[j][l]);
            }
        }
    }*/

    for (j = 0; j < NPROC; j++) {
    if (st.inuse[j] && st.pid[j] >= 3 && st.pid[j])
      break;
  }
  if (st.priority[j]!=tb[ctr]) {
    ctr++;
    tb[ctr]=st.priority[j];
  }
  while (1){
    getpinfo(&st);
    if (st.priority[j]!=tb[ctr]) {
      ctr++;
      tb[ctr]=st.priority[j];
    }
    int s=0;
    for (l = 3; l >= 0; l--)
    s+=st.ticks[j][l];
    if (s>=atoi(argv[1])) {
      printf(1,"Process ID:%d\n",mypid);
      for (l = 0; l <= 3; l++) {
        printf(1, "Queue level:%d \t xử lý:%d tick\n", l,
        st.ticks[j][l]);
      }
      printf(1, "Quá trình chuyển đổi giữa các hàng đợi ưu tiên: \n");
      for (l=0; l<=ctr; l++)
      {
        printf(1,"%d->",tb[l] );
      }
      printf(1,"\n");
      break;
    }
  }
    
    exit();
    return 0;
}




// {   
//     // char *temp = "hello";
//     struct pstat pstat;


//     // }
//     // cprintf("upar\n");
//     // pstat = (struct pstat*)malloc(sizeof(struct pstat*));
//     // cprintf("lower\n");
//     int i = 4;
//     i = getpinfo(&pstat);
//     printf(1, "pid \t name \t\t state \t\t priority \t\t ticks \n");
//     printf(1, "%d\n",i);
//     // printf(1, "%d", pstat.priority[1]);
//     // printf(1, "%d", pstat->priority[1]);

//     for(int i=0;i<64;i++){
//         if(pstat.inuse[i] == 1){
//         if(pstat.state[i] == SLEEPING)
//             printf(1, "\n%d \t %s \t\tSLEEPING \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         else if(pstat.state[i] == RUNNING)
//             printf(1, "\n%d \t %s \t\tRUNNING \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         else if(pstat.state[i] == RUNNABLE)
//             printf(1, "\n%d \t %s \t\tRUNNABLE \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         else if(pstat.state[i] == ZOMBIE)
//             printf(1, "\n%d \t %s \t\tZOMBIE \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         //else if(pstat.state[i] == UNUSED)
//             //cprintf("%d \t %s \t\tUNUSED \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         else if(pstat.state[i] == EMBRYO)
//             printf(1, "\n%d \t %s \t\t EMBRYO \t\t %d \t\t %d \n",pstat.pid[i],pstat.name[i], pstat.priority[i],pstat.ticks[i][pstat.priority[i]]);
//         }
//     }

//     exit();
// }
