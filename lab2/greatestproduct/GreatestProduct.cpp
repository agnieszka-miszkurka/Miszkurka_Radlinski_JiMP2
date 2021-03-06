//
// Created by Ignacy on 3/14/2017.
//

#include "GreatestProduct.h"

//wersja dOstateczna

int GreatestProduct(const vector<int> &v, int k)
{
    vector<int> nowy=v;
    sort(nowy.begin(),nowy.end());
    unsigned long dlg = nowy.size();
    int max, l=0;
    unsigned long p=dlg-1;
    if(k%2==0)
    {
        for(int i =0; i<k; i+=2)
        {
            int lewy = nowy[l]*nowy[l+1];
            int prawy = nowy[p] * nowy[p-1];
            if(lewy>=prawy) {
                l+=2;
            }
            if(lewy<prawy) {
                p -= 2;
            }
        }
        max = 1;
        for (int i=0; i<l; i++)
        {
            max *= nowy[i];
        }
        for (unsigned long i=dlg-1; i>p; i--)
        {
            max *= nowy[i];
        }
        return max;
    }
    else
    {
        for(int i =0; i<k; i+=2)
        {
            int lewy = nowy[l]*nowy[l+1];
            int prawy = nowy[p] * nowy[p-1];
            if(lewy>=prawy) {
                if (nowy[dlg-1]<0)
                    return prawy * nowy[p-2];
                else
                    return lewy*nowy[dlg-1];
            }
            if(lewy<prawy)
                return prawy*nowy[dlg-3];

        }
    }
    return 0;
}
