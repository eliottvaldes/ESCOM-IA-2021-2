-- SIMULACION DE COMPUERTA OR

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity SimulacionCompuertaOr is
--
end SimulacionCompuertaOr;

architecture Behavioral of SimulacionCompuertaOr is


component compuertaOr
 Port (   
    A : in STD_LOGIC;
    B :in STD_LOGIC;    
    Z : out STD_LOGIC
    );
end component;


signal A_s, B_s : STD_LOGIC:= '0';

signal Z_s : STD_LOGIC;



begin

UO: compuertaOr Port map (
A => A_s,
B => B_s,
Z => Z_s
);

process begin

A_s <= '0';
B_s <= '0';
wait for 100 ns;

A_s <= '0';
B_s <= '1';
wait for 100 ns;

A_s <= '1';
B_s <= '0';
wait for 100 ns;

A_s <= '1';
B_s <= '1';
wait for 100 ns;




wait;
end process;
end Behavioral;
