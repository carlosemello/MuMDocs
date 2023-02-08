// tutorial 2.cpp
#include "MuMaterial.h"

int main(void)
{
    MuMaterial mat1, mat2, matFinal;
    MuNote nota;
    
    srand(static_cast<unsigned int>(time(0)));
    nota.SetInstr(1);
    nota.SetStart(0.0);
    nota.SetDur(0.17);
    
    int turns = 10;
    
    while(turns--)
    {
        mat1.Clear();
        mat2.Clear();
        for(int i = 0; i < 7; i++)
        {
            if(i == 0)
                nota.SetAmp(0.75);
            else
                nota.SetAmp(0.4);
            nota.SetPitch(Between(48,60));
            mat1 += nota;
        }
        
        mat2 = mat1;
        
        // 8va abaixo / 8va acima
        int transp = 12;
        if (rand()%2) transp *= -1;
        mat2.Transpose(transp);
        mat1 += mat2;
        matFinal += mat1;
    }

    matFinal.PlaybackWithCsound("/Users/cem/Desktop/melodia");
    return 0;
}

