%%Declaración de matrices
matriz = [0.217, 0.732, 0.414; 0.508, 0.809, 0.376; 0.795, 0.886, 0.338;];
vector= [0.741; 0.613; 0.485];
MatrizAmp=[matriz vector];



fprintf("La matriz original es:\n")
disp(MatrizAmp)
opt=input("Como quieres resolver el sistema?\n1.-Eliminacio gaussiana 2.-Gauss-Jordan\n")
switch opt
    case 1
        vecSol=Elim_gaussiana(MatrizAmp);
    case 2
        GaussJordan(MatrizAmp);
    otherwise
        fprintf("Opcion invalida\n")
end


