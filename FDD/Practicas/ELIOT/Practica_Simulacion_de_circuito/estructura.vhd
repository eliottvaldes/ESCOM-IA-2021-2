------------------------------------------
-- EQUIPO FILA-DELFIA
------------------------------------------
-- Programa de caldera
-- 4 sensores (Presion, LLenado, Temperatura, Bomba)
------------------------------------------

LIBRARY IEEE;
USE IEEE.std_logic_1164.ALL;
USE IEEE.numeric_std.ALL;
USE IEEE.std_logic_unsigned.ALL;

ENTITY caldera IS
    PORT (
        P : IN STD_LOGIC;
        L : IN STD_LOGIC;
        B : IN STD_LOGIC;
        A : IN STD_LOGIC;
        S1 : OUT STD_LOGIC;
        S2 : OUT STD_LOGIC;
        S3 : OUT STD_LOGIC;
    );
END caldera;

ARCHITECTURE Behavioral OF caldera IS

BEGIN
    S1 <= NOT P AND L AND B AND NOT A;
    S2 <= NOT P AND NOT L;
    S3 <= (NOT P AND (((NOT B AND A) OR (L AND B)))) OR P;

END Behavioral;