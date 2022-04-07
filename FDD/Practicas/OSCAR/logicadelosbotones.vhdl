

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity botones is
port (
bo0:IN STD_LOGIC;
bo1:IN STD_LOGIC;
bo2:IN STD_LOGIC;
bo3:IN STD_LOGIC;
bo4:IN STD_LOGIC;
bo5:IN STD_LOGIC;
bo6:IN STD_LOGIC;
bo7:IN STD_LOGIC;
bo8:IN STD_LOGIC;
bo9:IN STD_LOGIC;
push:IN STD_LOGIC;
en:OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
end botones;

architecture Behavioral of botones is
begin
en(0)<=push and not bo0;
en(1)<=push and not bo0;
en(2)<=push and not bo0;
en(3)<=push and not bo0;
en(0)<=push and  bo1;
en(1)<=push and not bo1;
en(2)<=push and not bo1;
en(3)<=push and not bo1;
en(0)<=push and not bo2;
en(1)<=push and  bo2;
en(2)<=push and not bo2;
en(3)<=push and not bo2;
en(0)<=push and  bo3;
en(1)<=push and  bo3;
en(2)<=push and not bo3;
en(3)<=push and not bo3;
en(0)<=push and  bo3;
en(1)<=push and  bo3;
en(2)<=push and not bo3;
en(3)<=push and not bo3;
en(0)<=push and not bo4;
en(1)<=push and not bo4;
en(2)<=push and  bo4;
en(3)<=push and not bo4;
en(0)<=push and  bo5;
en(1)<=push and not bo5;
en(2)<=push and  bo5;
en(3)<=push and not bo5;
en(0)<=push and not bo6;
en(1)<=push and  bo6;
en(2)<=push and  bo6;
en(3)<=push and not bo6;
en(0)<=push and  bo7;
en(1)<=push and  bo7;
en(2)<=push and  bo7;
en(3)<=push and not bo7;
en(0)<=push and not bo8;
en(1)<=push and not bo8;
en(2)<=push and not bo8;
en(3)<=push and  bo8;
en(0)<=push and  bo9;
en(1)<=push and not bo9;
en(2)<=push and not bo9;
en(3)<=push and  bo9;
end Behavioral;
