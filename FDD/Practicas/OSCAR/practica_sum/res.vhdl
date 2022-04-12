LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
ENTITY todo IS
    PORT (
        bo0 : IN STD_LOGIC;
        bo1 : IN STD_LOGIC;
        bo2 : IN STD_LOGIC;
        bo3 : IN STD_LOGIC;
        bo4 : IN STD_LOGIC;
        bo5 : IN STD_LOGIC;
        bo6 : IN STD_LOGIC;
        bo7 : IN STD_LOGIC;
        bo8 : IN STD_LOGIC;
        bo9 : IN STD_LOGIC;
        push0 : IN STD_LOGIC;
        push1 : IN STD_LOGIC;
        menos : IN STD_LOGIC;
        mas : IN STD_LOGIC;
        unologico : IN STD_LOGIC;
        CI : IN STD_LOGIC;
        Ax0, Bx0, C0, D0, E0, F0, G0, Ax1, Bx1, C1, D1, E1, F1, G1 : OUT STD_LOGIC;
        multiplicacion : IN STD_LOGIC);
END todo;
ARCHITECTURE Behavioral OF todo IS
    SIGNAL A, B : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL seg, seg1, seg2, seg3 : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL resta, nueve, ocho, siete, seis : STD_LOGIC_VECTOR(3 DOWNTO 0);
    SIGNAL mag, mag1 : STD_LOGIC_VECTOR(2 DOWNTO 0);
    COMPONENT adder4b
        PORT (
            A, B : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            S : OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
            CI : IN STD_LOGIC;
            C0 : OUT STD_LOGIC);
    END COMPONENT;
    COMPONENT botones
        PORT (
            bo0 : IN STD_LOGIC;
            bo1 : IN STD_LOGIC;
            bo2 : IN STD_LOGIC;
            bo3 : IN STD_LOGIC;
            bo4 : IN STD_LOGIC;
            bo5 : IN STD_LOGIC;
            bo6 : IN STD_LOGIC;
            bo7 : IN STD_LOGIC;
            bo8 : IN STD_LOGIC;
            bo9 : IN STD_LOGIC;
            push : IN STD_LOGIC;
            en : OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
    END COMPONENT;
    COMPONENT bdc7
        PORT (
            B0, B1, B2, B3 : IN STD_LOGIC;
            A, B, C, D, E, F, G : OUT STD_LOGIC);
    END COMPONENT;
    COMPONENT multi
        PORT (
            A0 : IN STD_LOGIC;
            A1 : IN STD_LOGIC;
            B0 : IN STD_LOGIC;
            B1 : IN STD_LOGIC;
            s : OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
    END COMPONENT;
    COMPONENT compardor
        PORT (
            A, B : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
            AmaB, AmeB, AB : OUT STD_LOGIC);
    END COMPONENT;
BEGIN
    --representacion en bianrio de algunos numeros 
    nueve(0) <= unologico;
    nueve(1) <= NOT unologico;
    nueve(2) <= NOT unologico;
    nueve(3) <= unologico;
    ocho(0) <= NOT unologico;
    ocho(1) <= NOT unologico;
    ocho(2) <= NOT unologico;
    ocho(3) <= unologico;
    siete(0) <= unologico;
    siete(1) <= unologico;
    siete(2) <= unologico;
    siete(3) <= NOT unologico;
    seis(0) <= NOT unologico;
    seis(1) <= unologico;
    seis(2) <= unologico;
    seis(3) <= NOT unologico;
    resta(0) <= NOT unologico;
    resta(1) <= unologico;
    resta(2) <= NOT unologico;
    resta(3) <= NOT unologico;
    A1 : botones--senal binaria de cada boton en la entrada a
    PORT MAP(bo0, bo1, bo2, bo3, bo4, bo5, bo6, bo7, bo8, bo9, push0, A);
    B1 : botones--senal binaria de cada entrada del boton b, debe presionarse el boton para la entrada a para que envie la senal binaria 
    PORT MAP(bo0, bo1, bo2, bo3, bo4, bo5, bo6, bo7, bo8, bo9, push1 AND push0, B);
    U0 : adder4b-- hace la uma de las entradas a y b
    PORT MAP(A, (push0 AND(B(0) XOR menos), push0 AND(B(1)XOR menos), push0 AND(B(2)XOR menos), push0 AND(B(3)XOR menos)), seg, CI, seg3(3));
    Com : compardor
    PORT MAP(seg, nueve, mag(0), mag(1), mag(2));
    Commulti : compardor-- verifica que las entradas del multiplicador no sean mayor a 3 bits, de ser mayores el multiplicador no hara nada
    PORT MAP(seg, (unologico, unologico, NOT unologico, NOT unologico), mag1(0), mag1(1), mag1(2));
    U1 : adder4b--resta 2 al resultado de la primera si este es mayor 9  
    PORT MAP(seg, ((resta(0)XOR unologico), (resta(1)XOR unologico), (resta(2)XOR unologico), (resta(3)XOR unologico)), seg2, CI, seg3(0));
    M0 : multi-- multiplicador
    PORT MAP(A(0)AND mag1(2), A(1)AND mag1(2), B(0)AND mag1(2), B(1)AND mag1(2), seg1);
    bcd : bdc7
    PORT MAP((((seg(0)AND NOT mag(0)) OR (seg2(0)AND mag(0)) OR ((seg1(0)AND multiplicacion)AND NOT(mas XOR menos)))AND NOT seg3(3)) OR ((seg3(3)AND seg(0))), (((seg(1)AND NOT mag(0)) OR (seg2(1)AND mag(0)) OR ((seg1(1)AND multiplicacion)AND NOT(mas XOR menos)))AND NOT seg3(3)) OR ((seg3(3)AND NOT seg(1))) OR ((seg3(3)AND seg(0))), (((seg(2)AND NOT mag(0)) OR (seg2(2)AND mag(0)) OR ((seg1(2)AND multiplicacion)AND NOT(mas XOR menos)))AND NOT seg3(3)) OR ((seg3(3)AND NOT seg(1))) OR ((seg3(3)AND seg(0))), (((seg(3)AND NOT mag(0)) OR (seg2(3)AND mag(0)) OR ((seg1(3) AND multiplicacion)AND NOT(mas XOR menos)))AND NOT seg3(3)) OR ((seg3(3)AND seg(1))), Ax0, Bx0, C0, D0, E0, F0, G0);
    bcd1 : bdc7
    PORT MAP(mag(0), NOT unologico, NOT unologico, NOT unologico, Ax1, Bx1, C1, D1, E1, F1, G1);
END Behavioral;