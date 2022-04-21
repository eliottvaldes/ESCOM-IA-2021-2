function Gauss_Jordan=GaussJordan(X)%%Funcion gauss jordan
     MatrizAmp=X;
    for i=2:3
        pivote=MatrizAmp(i,1)/MatrizAmp(1,1);%%posicion que se quiere eliminar sobre la fila que vayamos a usar
        for j=1:4
            MatrizAmp(i,j)=MatrizAmp(i,j)-(pivote*MatrizAmp(1,j));%%Se eliminan las primeras filas
        end
    end

    pivote=MatrizAmp(3,2)/MatrizAmp(2,2);
    for i=2:4
        MatrizAmp(3,i)=MatrizAmp(3,i)-(MatrizAmp(2,i)*pivote);%%se elimina el termino central inferior
    end

   
    for i=1:2%%eliminar posicion 1,3 y 2,3
        pivote=MatrizAmp(i,3)/MatrizAmp(3,3);
        for j=1:4
            MatrizAmp(i,j)=MatrizAmp(i,j)-(MatrizAmp(3,j)*pivote);
        end
    end
    pivote=MatrizAmp(1,2)/MatrizAmp(2,2);
    MatrizAmp(1,2)=MatrizAmp(1,2)-(MatrizAmp(2,2)*pivote);
    for i=1:3
        for j=1:4
                MatrizAmp(i,j)=MatrizAmp(i,j)/MatrizAmp(i,i);
        end
    end
    disp(MatrizAmp)
Gauss_Jordan=MatrizAmp;
end