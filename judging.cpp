Block judging(Block judge[] ,int allnum, int isnum){//共有幾個物件

    for(int i=0;i<allnum;i++){//重置
        if(judge[i].lop=1){
            judge[i].isyou=0;
            judge[i].wol=2;
            judge[i].pu=0;
            judge[i].snk=0;
            judge[i].stp=0;
        }
        if(judge[i].lop=0){
            judge[i].isyou=0;
            judge[i].wol=2;
            judge[i].pu=1;
            judge[i].snk=0;
            judge[i].stp=0;
        }

    }
    int x[100];
    int y[100];
    for(int i=0;i<100;i++){
        x[i]=judge[i].x;
    }
    for(int i=0;i<100;i++){
        y[i]=judge[i].y;
    }

    int isnumx[isnum];
    int isnumy[isnum];
    for(int i=0;i<isnum;i++){

            isnumx[i]=judge[i].x;
            isnumy[i]=judge[i].y;

    }
    struct Match{
    int num,
    int subx,
    int objx,
    int suby,
    int objy,
    int subobjx,
    int subobjy
    };

    Match match[isnum];
    for(int i=0;i<isnum;i++){
        match[i].num=1;
    }


    for(int i=0;i<isnum;i++){
        for(int j=0;j<allnum;j++){
            if(judge[j].mode==0){
                if((judge[j].x==isnumx[i])&&(judge[j].y==isnumy[i]-1)) {match[i].num*=2; subx=j;}
            }

            if(judge[j].mode==0){
                if((judge[j].x==isnumx[i]-1)&&(judge[j].y==isnumy[i])) {match[i].num*=5; suby=j;}
            }
            if(judge[j].mode==1){
                if((judge[j].x==isnumx[i])&&(judge[j].y==isnumy[i]+1)) {match[i].num*=3; objx=j;}
            }
            if(judge[j].mode==1){
                if((judge[j].x==isnumx[i]+1)&&(judge[j].y==isnumy[i])) {match[i].num*=7; objy=j;}
            }
            if(judge[j].mode==0){
                if((judge[j].x==isnumx[i])&&(judge[j].y==isnumy[i]+1)) {match[i].num*=11; subobjx=j;}
            }
            if(judge[j].mode==0){
                if((judge[j].x==isnumx[i]+1)&&(judge[j].y==isnumy[i])) {match[i].num*=13; subobjy=j;}
            }

        }
    }

    for(int i=0;i<isnum;i++){
        if(match[i].num%6==0){
            if(judge[objx].which==0){
                judge[subx].isyou=1;
            }
            if(judge[objx].which==1){
                judge[subx].snk=1;
            }
            if(judge[objx].which==2){
                judge[subx].stp=1;
            }
            if(judge[objx].which==3){
                judge[subx].pu=1;
            }
            if(judge[objx].which==4){
                judge[subx].wol=0;
            }
            if(judge[objx].which==5){
                judge[subx].wol=1;
            }

        //1.重新set值
        //2.if sub is sub

            }
        }
        if(match[i].num%35==0){
            if(judge[objy].which==0){
                judge[suby].isyou=1;
            }
            if(judge[objy].which==1){
                judge[suby].snk=1;
            }
            if(judge[objy].which==2){
                judge[suby].stp=1;
            }
            if(judge[objy].which==3){
                judge[suby].pu=1;
            }
            if(judge[objy].which==4){
                judge[suby].wol=0;
            }
            if(judge[objy].which==5){
                judge[suby].wol=1;
            }
        }
        if(match[i].num%22==0){
            judge[subx].which=judge[subobjx].which;
            judge[subx].isyou=judge[subobjx].isyou;
            judge[subx].wol=judge[subobjx].wol;
            judge[subx].pu=judge[subobjx].pu;
            judge[subx].snk=judge[subobjx].snk;
            judge[subx].stp=judge[subobjx].stp;

        }
        if(match[i].num%65==0){
            judge[suby].which=judge[subobjy].which;
            judge[suby].isyou=judge[subobjy].isyou;
            judge[suby].wol=judge[subobjy].wol;
            judge[suby].pu=judge[subobjy].pu;
            judge[suby].snk=judge[subobjy].snk;
            judge[suby].stp=judge[subobjy].stp;
        }
    }
    return judge;
}
