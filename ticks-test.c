#include "types.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"

int
main(int argc, char *argv[])
{
  int tb[100]={0};
  int ctr=0;
  tb[0]=3;
  struct pstat st;

  if(argc != 2){
    printf(1, "usage: ticks-test counter\n");
    exit();
  }

  int /* i, x, */ l, j;
  int mypid = getpid();

  getpinfo(&st);

  for (j = 0; j < NPROC; j++) {
    if (st.inuse[j] && st.pid[j] >= 3 && st.pid[j] == mypid)
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
      printf(1,"ID:%d\n",mypid);
      for (l = 3; l >= 0; l--) {
        printf(1, "level:%d \t ticks-used:%d\n", l,
        st.ticks[j][l]);
      }
      printf(1, "Lich trinh trong PQ:");
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
