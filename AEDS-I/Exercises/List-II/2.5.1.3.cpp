#include<iostream.h>
using namespace std;
int main()
{
    int vetor[1000], limite, n, aparece, m=0, conjuntoc[1000], c=0, repete, limite2=0;
    cout << "Quantos n�meros voc� deseja inserir?\n";
    cin >> limite;
    limite=limite-1; 
    cout << "Digite os n�meros na ordem crescente.\n";
    for (n=0; n<=limite; n++)
        {
        cout << "Digite o n�mero\n";
        cin >> vetor [n];
        }
   while (m<=limite)
         {
         aparece=1;
         while (vetor[m]==vetor[m+1])
            {
            aparece=aparece+1;
            m++;
            }
         m++;
         if (aparece>1)
            {
            cout << "O n�mero "<< vetor[m-1] << " aparece " << aparece << " vezes.\n";
            }
         }
   cout << "\n\n";
   m=0;
   while (m<=limite)
         {
         repete=0;
         while (vetor[m]==vetor[m+1])
               {
               repete=repete+1;
               m++;
               }
         m++;
         if (repete==0)
            {
            conjuntoc[c]=vetor[m-1];
            }
         else
             {
             conjuntoc[c]=vetor[m-1];
             }
         c++;
         limite2++;
         }
   cout << "O n�mero em ordem crescente e sem repeti��o s�o:\n";
   for (n=0; n<=limite2-1; n++)
       {
       cout << conjuntoc[n] << "\t";
       }
   cout << "\n";
   return 0;
}
