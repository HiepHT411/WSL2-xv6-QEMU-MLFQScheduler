#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
int
main(int argc, char *argv[]){
    // int k, n, id; 
    // double x = 0, z, d;
    // if (argc<2)
    //     n = 1;
    // else
    //     n = atoi(argv[1]);

    // if (n<0||n>20)
    //     n = 2;
    // if (argc<3)
    //     d = 1.0;
    // else
    //     d = atoi(argv[2]);
    
    // x = 0;
    // id = 0;
    // for (k=0;k<n;k++){
    //     id = fork();
    //     if (id<0){
    //         printf(1,"%d failed in fork!\n",getpid());
    //     } 
    //     else if (id>0){
    //         wait();
    //         printf(1, "%d Creating Child %d\n",getpid(),id);
            
    //     }
    //     else{
    //         printf(1, "Child %d created\n", getpid());
    //         for (z = 0; z<8000000; z+=d ){
    //             x = x + 3.14*89.64;
    //             break;
    //         }
    //     }
    // }
    int id = 0; 
    int x = 1;
    id = fork();
    if (id<0){
        printf(1,"%d failed in fork!\n",getpid());
        } 
    else if (id>0){
        while(1){
            x = x*1.000000000001;
        }
        printf(1, "%d Creating Child %d\n",getpid(),id);
            
    }
    else{
        printf(1, "Child %d created\n", getpid());
        while(1){
            x = x*1.000000000001;
        } 
            
        }
    exit();
}
