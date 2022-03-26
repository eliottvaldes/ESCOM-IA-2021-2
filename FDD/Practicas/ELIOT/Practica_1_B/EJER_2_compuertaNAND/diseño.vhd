------------------------------------------
-- Valdés Luis Eliot Fabián
-- Practica 1_ejc 2

-- DISEÑO DE COMPUERTA NAND
------------------------------------------

library IEEE;

use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity compuertaNand is
  Port ( 
  
    A : in STD_LOGIC;
    B :in STD_LOGIC;
    
    Z : out STD_LOGIC
  );
end compuertaNand ;


architecture Behavioral of compuertaNand is


begin


Z <= A nand B;

end Behavioral;
