#include<stdio.h>
#include<stdlib.h>
int head,pre,n,i,j,a[50],move=0,temp,size,hd;
void main()
{
    printf("Enter the current head position : ");
    scanf("%d",&head);
    size=200-1;
    printf("Enter the previous position : ");
    scanf("%d",&pre);
    printf("Enter the no. of request : ");
    scanf("%d",&n);
    printf("Enter the request : ");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    hd=head;
    if(pre<head){
        printf("The sequence is : %d",head);
        for (i=0;i<n;i++) {
            if (a[i]>=hd) {
                printf("->%d",a[i]);
                move+=abs(a[i]-head);
                head=a[i];
            }
        }
        printf("->%d",size);
        move+=abs(size-head);
        head=size;
        printf("->0");
        move+=size;
        head=0;
        for (i=0;i<n;i++) {
            if (a[i]<hd) {
                printf("->%d",a[i]);
                move+=abs(a[i]-head);
                head=a[i];
            }
        }
        printf("\n Total Head Movement = %d ",move);
    }
    else {
        printf("The sequence is : %d",head);
        for (i=n-1;i>=0;i--) {
            if (a[i]<hd) {
                printf("->%d",a[i]);
                move+=abs(a[i]-head);
                head=a[i];
            }
        }
        printf("->0");
        move+=head;
        move+=size;
        head=0;
        printf("->%d",size);
        head=size;
        for (i=n-1;i>=0;i--) {
            if (a[i]>=hd) {
                printf("->%d",a[i]);
                move+=abs(a[i]-head);
                head=a[i];
            }
        }
        printf("\n Total Head Movement = %d ",move);
    }
}