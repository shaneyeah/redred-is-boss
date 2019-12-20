Block initialize(Block initial ,int leveln, int allnum, int redrednum, int flagnum, int wallnum,
                int rocknum, int waternum, int lavanum, int grassnum, int younum, int sinknum, int stopnum,
                int pushnum, int wanum, int acnum, int isnum,int picredrednum, int picflagnum, int picwallnum
                , int picrocknum, int picwaternum ,int piclavanum , int picgrassnum){

    int sum=0;
    int sumlast=0;
    sum += redrednum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=0;
    }
    sumlast=sum;
    sum += flagnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=1;
    }
    sumlast=sum;
    sum += wallnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=2;
    }
    sumlast=sum;
    sum += rocknum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=3;
    }
    sumlast=sum;
    sum += waternum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=4;
    }
    sumlast=sum;
    sum += lavanum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=5;
    }
    sumlast=sum;
    sum += grassnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=6;
    }
    sumlast=sum;
    sum += younum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=0;
    }
    sumlast=sum;
    sum += sinksum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=1;
    }
    sumlast=sum;
    sum += stopnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=2;
    }
    sumlast=sum;
    sum += pushnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=3;
    }
    sumlast=sum;
    sum += wanum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=4;
    }
    sumlast=sum;
    sum += acnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 1;
        initial[leveln][i].which=5;
    }
    sumlast=sum;
    sum += isnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=0;
        initial[leveln][i].mode = 2;
        initial[leveln][i].which=0;
    }
    int sum=0;
    int sumlast=0;
    sum += picredrednum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=0;
    }
    sumlast=sum;
    sum += picflagnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=1;
    }
    sumlast=sum;
    sum += picwallnum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i]which=2;
    }
    sumlast=sum;
    sum += picrocknum;
    for(int i=sumlast;i<sum;i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=3;
    }
    sumlast=sum;
    sum += picwaternum;
    for(int i=sumlast;i<sum; i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=4;
    }
    sumlast=sum;
    sum += piclavanum;
    for(int i=sumlast;i<sum ;i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=5;
    }
    sumlast=sum;
    sum += picgrassnum;
    for(int i=sumlast;i<sum; i++){
        initial[leveln][i].lop=1;
        initial[leveln][i].mode = 0;
        initial[leveln][i].which=6;
    }
    for(int i=sum;i<100;i++){
        initial[level][i].mode =-1;
    }


    return initial;
}
