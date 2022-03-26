-- SIMULACION DE funcion ( (A + B) · C )’ = Z

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity SimulacionFuncion is
--
end SimulacionFuncion;

architecture Behavioral of SimulacionFuncion is


component funcion
 Port (   
    A : in STD_LOGIC;
    B :in STD_LOGIC;    
    C :in STD_LOGIC;    
    Z : out STD_LOGIC
    );
end component;


signal A_s, B_s, C_s : STD_LOGIC:= '0';

signal Z_s : STD_LOGIC;



begin

UO: funcion Port map (
A => A_s,
B => B_s,
C => C_s,
Z => Z_s
);

process begin

-- PONER TODAS LAS COMBINACIONES DE LA TABLA DE VERDAD
A_s <= '0';
B_s <= '0';
C_s <= '0';
wait for 100 ns;

A_s <= '1';
B_s <= '0';
C_s <= '0';
wait for 100 ns;

A_s <= '0';
B_s <= '1';
C_s <= '0';
wait for 100 ns;

A_s <= '0';
B_s <= '0';
C_s <= '1';
wait for 100 ns;

A_s <= '1';
B_s <= '1';
C_s <= '0';
wait for 100 ns;

A_s <= '1';
B_s <= '0';
C_s <= '1';
wait for 100 ns;

A_s <= '0';
B_s <= '1';
C_s <= '1';
wait for 100 ns;

A_s <= '1';
B_s <= '1';
C_s <= '1';
wait for 100 ns;



wait;
end process;
end Behavioral;
