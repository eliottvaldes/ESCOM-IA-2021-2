------------------------------------------
-- Valdés Luis Eliot Fabián
-- Practica 1_ejc 3


-- DISEÑO DE funcion ( (A + B) · C )’ = Z
-- ((A OR B) AND C)'
------------------------------------------

library IEEE;

use IEEE.std_logic_1164.all;
use IEEE.numeric_std.all;
use IEEE.std_logic_unsigned.all;


entity funcion is
  Port ( 
  
    A : in STD_LOGIC;
    B :in STD_LOGIC;
    C :in STD_LOGIC;
    
    Z : out STD_LOGIC
  );
end funcion ;


architecture Behavioral of funcion is


begin


Z <= not ((A or B) and C);

end Behavioral;
