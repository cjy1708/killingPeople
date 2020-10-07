#include <stdio.h>
#include <stdbool.h>

int main(){
    bool n[1000] = {0};//指示是否存活
    int liveNumber = 0;//总人数
    int T = 0;//死亡周期
    int prognosis = 0;//预判死亡
    int death = 0;//死亡人数

    printf("请输入参与人数：");
    scanf("%d",&liveNumber);
    printf("请输入死亡周期：");
    scanf("%d",&T);
    for(int i = 0;i < liveNumber;i++){
        n[i] = 1;//给参与值定为一
    }
    //开始杀人
    for(int y = 0;;y++) {
        if (n[y] == 1) prognosis++;//数存活人数
        if (prognosis == T){
            n[y] = 0;
            prognosis = 0;
            death++;
        }
        //超过总序号就重来
        if (y >= liveNumber) y = -1;
        //只剩一人了，就跳出
        if (liveNumber - death == 1)
            break;
    }
    for(int z = 0;z < liveNumber;z++){
        if (n[z] == 1)
            printf("最后幸存者编号：%d",z+1);
    }
    return 0;
}
