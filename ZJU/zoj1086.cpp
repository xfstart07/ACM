#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    char dk[100];
    while (scanf("%s",dk) != EOF) {
        char dm[100] = {'0'};
        int len = 0;
        for (int i=strlen(dk)-1;i>1;--i) {
            int num = dk[i] - '0';
            int tmp,j;
            for (j=0;j<len || num;++j) {
                tmp = num*10 + (j<len?dm[j]-'0':0);
                dm[j] = (int)(tmp/8) + '0';
                num = tmp%8;
            }   // ³ý·¨
            len = j;
        }
        dm[len]='\0';
        printf("%s [8] = 0.%s [10]\n",dk,dm);
    }
    return 0;
}
