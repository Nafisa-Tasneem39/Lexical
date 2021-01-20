#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[500],b,c,i,j,k,l,m,n;
    int ans_1,chk;
    double tt,bb,mm;
    char a_1[500],a_2[500],a_3[500],a_4[500];
    string store;

    gets(a_1);
    l = strlen(a_1);
    chk = 0;
    j = k = b = 0;
    for(i=0;i<l;i++)
    {
        if(a_1[i]!=' ' && chk==0)
            store += a_1[i];
        else if(a_1[i]!=' ' && chk==1)
        {
            if(a_1[i]>='a' && a_1[i]<='z')
                j++, a_2[j] = a_1[i];
            else if(a_1[i]=='+' || a_1[i]=='-' || a_1[i]=='*' || a_1[i]=='/')
                k++, a_3[k] = a_1[i];
            else if(a_1[i]==';' || a_1[i]==',' || a_1[i]==':')
                b++, a_4[b] = a_1[i];
        }
        else if(a_1[i]==' ')
        {
            if(!chk)
                chk = 1, cout<<"Keyword: "<<store<<'\n';
        }
    }
    printf("Variable: ");
    for(i=1;i<=j;i++)
    {
        if(i!=j)
            printf("%c,",a_2[i]);
        else
           printf("%c\n",a_2[i]);
    }
    printf("Arithmetic Operator: ");
    for(i=1;i<=k;i++)
    {
        if(i!=k)
            printf("%c,",a_3[i]);
        else
            printf("%c\n",a_3[i]);
    }
    printf("Punctuation: ");
    for(i=1;i<=b;i++)
    {
        if(i!=b)
            printf("%c,",a_4[i]);
        else
            printf("%c\n",a_4[i]);
    }
    j = k = ans_1 = chk = 0;
    for(i=l-1;i>=0;i--)
    {
        if(a_1[i]>='0' && a_1[i]<='9')
        {
            tt = pow(10,j);
            b = tt;
            ans_1 += (a_1[i] - 48) * b;
            j++;
        }
        else
        {
            j = 0;
            if(ans_1)
                k++, a[k] = ans_1;
            ans_1 = 0;
        }
    }
    printf("Constant: ");
    for(i=1;i<=k;i++)
    {
        if(i!=k)
            printf("%d,",a[i]);
        else
            printf("%d\n",a[i]);
    }

    return 0;
}
