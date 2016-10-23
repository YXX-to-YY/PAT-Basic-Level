#include <stdio.h>
#include <stdlib.h>

int CheckCode(char *s, int *weight ){ //计算一个身份证的校验码，并返回
    int Z = -1;//-1表示此身份证不符合规范
    char M = ' '; //最终校验码
    int sum = 0;

    //检测是否符合规范，并计算Z值：
    for(int i=0; i<17; i++){
        if(s[i] > '9' || s[i] < '0') //检测前17位是否全为数字：
            return -1;
        else{
            sum += (s[i] - '0') * weight[i];    //加权求和
        }
    }
    Z = sum % 11;

    //根据Z值，生成最终验证码M：
    switch(Z)
    {
        case 0:
            M = '1';
            break;
        case 1:
            M = '0';
            break;
        case 2:
            M = 'X';
            break;
        case 3:
            M = '9';
            break;
        case 4:
            M = '8';
            break;
        case 5:
            M = '7';
            break;
        case 6:
            M = '6';
            break;
        case 7:
            M = '5';
            break;
        case 8:
            M = '4';
            break;
        case 9:
            M = '3';
            break;
        case 10:
            M = '2';
            break;
    }
    return M;
}

int verify(char M, char *s){ //看Z值与身份证最后一个字符是否相等
    return (M == s[17])? 1 : 0;
}

int main(){
    int N;
    scanf("%d",&N);

    //利用字符串数组，记录每一个身份证号
    char **arr = (char **)malloc(N * sizeof(char *));
    for(int i=0; i<N ;i++){
        arr[i] = (char *)malloc(19 * sizeof(char));
        scanf("%s",arr[i]);
    }
    //权重：
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

    //遍历每一个身份证:
    int M;  //生成的验证码
    int count = 0;  //错误的身份证个数
    for(int i=0; i<N; i++){
        M = CheckCode(arr[i],weight);
        if(verify(M,arr[i]) == 0){
            count++;
            printf("%s\n",arr[i]);
        }
    }
    if(count == 0)
        printf("All passed\n");
    return 0;
}
