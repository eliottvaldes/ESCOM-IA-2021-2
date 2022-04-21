%%Declaración de matrices
matriz = [0.217, 0.732, 0.414; 0.508, 0.809, 0.376; 0.795, 0.886, 0.338;];
vector= [0.741; 0.613; 0.485];
vecSol=[0;0;0;];
MatrizAmp=[matriz vector];

%%Eliminación Gaussiana

fprintf("La matriz original es: ")
disp(MatrizAmp)

for i=2:3
    pivote=MatrizAmp(i,1)/MatrizAmp(1,1);
    for j=1:4
    MatrizAmp(i,j)=MatrizAmp(i,j)-(pivote*MatrizAmp(1,j));%%Se eliminan las primeras 2 columnas
    end
end

pivote=MatrizAmp(3,2)/MatrizAmp(2,2);
for i=2:4
    MatrizAmp(3,i)=MatrizAmp(3,i)-(MatrizAmp(2,i)*pivote)
end

%%Sustitucion hacia atras
X3=MatrizAmp(3,4)/MatrizAmp(3,3);
X2=(MatrizAmp(2,4)-(X3*MatrizAmp(2,3)))/MatrizAmp(2,2);
X1=(MatrizAmp(1,4)-(X2+X3))/MatrizAmp(1,1);
vecSol=[X1;X2;X3];
fprintf("La solucion al sistema es:\n")
disp(vecSol);
