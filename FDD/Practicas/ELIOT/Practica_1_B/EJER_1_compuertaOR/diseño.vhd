------------------------------------------
-- Valdés Luis Eliot Fabián
-- Practica 1_ejc 1

-- DISEÑO DE COMPUERTA OR
------------------------------------------

library IEEE;

use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;

entity compuertaOr is
  Port ( 
 
    A : in STD_LOGIC;
    B :in STD_LOGIC;
   
    Z : out STD_LOGIC
  );
end compuertaOr ;


architecture Behavioral of compuertaOr is


begin

Z <= A or B;

end Behavioral;
