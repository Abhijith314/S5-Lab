#include<stdio.h>
struct process {
int pno,at,bt,ct,tt,wt,pri;
};
void main()
{
    int n,i,j,pos,t,b,prio;
    float sumtt=0,sumwt=0;
    printf("Enter the number of process : ");
    scanf("%d",&n);
    struct process p[n],temp;
    printf("Enter the Process no., Arrival time, Burst time and Priority of :-\n");
    for(i=0;i<n;i++) {
        printf("Process : ");
        scanf("%d %d %d %d",&p[i].pno,&p[i].at,&p[i].bt,&p[i].pri);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i].at>p[j].at) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<n;i++) {
        if(i!=0)
            t=p[i-1].ct;
        else
            t=p[i].at;
        prio=p[i].pri;
        for(j=i;j<n;j++) {
            if((p[j].at<=t)&&(p[j].pri==prio)) {
                if(p[i].bt>p[j].bt)
                    pos=j;
                else
                    pos=i;
                prio=p[j].pri;
            }
            else if((p[j].at<=t)&&(p[j].pri<prio)) {
                pos=j;
                prio=p[j].pri;
            }
        }
        p[pos].ct=t+p[pos].bt;
        p[pos].tt=p[pos].ct-p[pos].at;
        p[pos].wt=p[pos].tt-p[pos].bt;
        sumwt+=p[pos].wt;
        sumtt+=p[pos].tt;
        temp=p[pos];
        p[pos]=p[i];
        p[i]=temp;
    }
    i=0;
    printf("\nGANTT CHART\n%d",p[i].at);
    for (i=0;i<n;i++) {
        printf("    P%d    %d",p[i].pno,p[i].ct);
    }
    printf("\n\nProcess no.\tArrival Time\tPriority\tBurst time\tTurnaround time\tWaiting time\tCompletion time\n");
    for(i=0;i<n;i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].pno,p[i].at,p[i].pri,p[i].bt,p[i].tt,p[i].wt,p[i].ct);
    }
    printf("Average Turnaround time = %f\n",sumtt/n);
    printf("Average Waiting time = %f\n",sumwt/n);
}
