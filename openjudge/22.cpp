#include<cstdio>
#include<cstring>

char my_email[60];
int n;
char name[60], password[60], email[60];
bool flag;

int main()
{
    scanf("%s", my_email);
    scanf("%d\n", &n);
    flag = false;
    for(int i=1; i<=n; ++i)
    {
        scanf("%s %s %s", name, password, email);
        if(strcmp(my_email, email) == 0)
        {
            flag = true;
            int len = strlen(password);
            for(int j=0; j<len; ++j)
            {
                if(password[j] >= 'a' && password[j] <= 'z')
                    password[j] = password[j] - 'a' + 'A';
                else if(password[j] >= 'A' && password[j] <= 'Z')
                    password[j] = password[j] - 'A' + 'a';
            }
            printf("%s %s\n", name, password);
        }
    }
    if(flag == false)
    {
        printf("empty");
    }
    return 0;
}