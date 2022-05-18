------------------------------------------
-- EQUIPO FILA-DELFIA
------------------------------------------
-- SIMULACION DE CALDERA
------------------------------------------

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
ENTITY SimulacionCaldera IS
    --
END SimulacionCaldera;

ARCHITECTURE Behavioral OF SimulacionCaldera IS
    COMPONENT caldera
        PORT (

            P : IN STD_LOGIC;
            L : IN STD_LOGIC;
            B : IN STD_LOGIC;
            A : IN STD_LOGIC;
            S1 : OUT STD_LOGIC;
            S2 : OUT STD_LOGIC;
            S3 : OUT STD_LOGIC

        );
    END COMPONENT;
    SIGNAL P_s, L_s, B_s, A_s : STD_LOGIC := '0';

    SIGNAL S1_s, S2_s, S3_s : STD_LOGIC;

BEGIN

    UO : caldera PORT MAP(
        P => P_s,
        L => L_s,
        B => B_s,
        A => A_s
    );

    PROCESS BEGIN

        -- PONER TODAS LAS COMBINACIONES DE LA TABLA DE VERDAD

        P_s <= '0';
        L_s <= '0';
        B_s <= '0';
        A_s <= '0';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '0';
        B_s <= '0';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '0';
        B_s <= '1';
        A_s <= '0';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '1';
        B_s <= '0';
        A_s <= '0';

        WAIT FOR 100 ns;
        P_s <= '1';
        L_s <= '0';
        B_s <= '0';
        A_s <= '0';

        WAIT FOR 100 ns;

        P_s <= '0';
        L_s <= '0';
        B_s <= '1';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '1';
        B_s <= '0';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '1';
        L_s <= '0';
        B_s <= '0';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '1';
        B_s <= '1';
        A_s <= '1';

        WAIT FOR 100 ns;

        P_s <= '1';
        L_s <= '0';
        B_s <= '1';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '0';
        L_s <= '1';
        B_s <= '1';
        A_s <= '1';

        WAIT FOR 100 ns;
        P_s <= '1';
        L_s <= '1';
        B_s <= '1';
        A_s <= '1';

        WAIT FOR 100 ns;

        WAIT;
    END PROCESS;
END Behavioral;