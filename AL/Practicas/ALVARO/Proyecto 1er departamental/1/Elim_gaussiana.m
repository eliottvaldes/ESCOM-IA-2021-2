function Sol=Elim_gaussiana(x)
    MatrizAmp=x;
    
        
    for i=2:3%&i se mueve por las filas
        pivote=MatrizAmp(i,1)/MatrizAmp(1,1);
        for j=1:4%%J se mueve por las columnas
            MatrizAmp(i,j)=MatrizAmp(i,j)-(pivote*MatrizAmp(1,j));%%Se eliminan las primeras 2 columnas
        end
    end

    pivote=MatrizAmp(3,2)/MatrizAmp(2,2);
    for i=2:4
    MatrizAmp(3,i)=MatrizAmp(3,i)-(MatrizAmp(2,i)*pivote);
    end
    
%%Sustitucion hacia atras
    X3=MatrizAmp(3,4)/MatrizAmp(3,3);
    X2=(MatrizAmp(2,4)-(X3*MatrizAmp(2,3)))/MatrizAmp(2,2);
    X1=(MatrizAmp(1,4)-(X2+X3))/MatrizAmp(1,1);
    Sol=[X1;X2;X3];
    fprintf("La solucion al sistema por eliminación gaussiana es:\n")
    disp(Sol);
end