

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity multi is
Port (
A0:in STD_LOGIC;
A1:in STD_LOGIC;
B0:in STD_LOGIC;
B1:in STD_LOGIC;
s:OUT STD_LOGIC_VECTOR(3 DOWNTO 0)); 
end multi;

architecture Behavioral of multi is
component mediosum
port(
           A : in STD_LOGIC;
           B : in STD_LOGIC;
           C : out STD_LOGIC;
           S : out STD_LOGIC);
end component;
signal m1,m2,m3,ci:STD_LOGIC;
begin
s(0)<=A0 and B0;
m1<=A1 and B0;
m2<=A0 and B1;
m3<=A1 and B1;
sum1:mediosum
port map(m1,m2,ci,s(1));
sum2:mediosum
port map(m3,ci,S(3),s(2));
end Behavioral;
