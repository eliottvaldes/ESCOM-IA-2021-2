library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
entity todo is
port(
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
push0:IN STD_LOGIC;
push1:IN STD_LOGIC;
menos:IN STD_LOGIC;
mas:IN STD_LOGIC;
unologico:IN STD_LOGIC;
CI:IN STD_LOGIC;
Ax0,Bx0,C0,D0,E0,F0,G0,Ax1,Bx1,C1,D1,E1,F1,G1 :out STD_LOGIC;
multiplicacion:IN STD_LOGIC);
end todo;
architecture Behavioral of todo is
signal A,B: STD_LOGIC_VECTOR(3 DOWNTO 0);
signal seg,seg1,seg2,seg3: STD_LOGIC_VECTOR(3 DOWNTO 0);
signal resta,nueve,ocho,siete,seis: STD_LOGIC_VECTOR(3 DOWNTO 0);
signal mag: STD_LOGIC_VECTOR(2 DOWNTO 0);
component adder4b
PORT(
A,B:IN STD_LOGIC_VECTOR(3 DOWNTO 0);
S:OUT STD_LOGIC_VECTOR(3 DOWNTO 0);
CI:IN STD_LOGIC;
C0:OUT STD_LOGIC);
end component;
component botones
port(
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
end component;
component bdc7
port ( 
B0,B1,B2,B3 : in STD_LOGIC;
A,B,C,D,E,F,G : out STD_LOGIC);
end component;
component multi
PORT(
A0:in STD_LOGIC;
A1:in STD_LOGIC;
B0:in STD_LOGIC;
B1:in STD_LOGIC;
s:OUT STD_LOGIC_VECTOR(3 DOWNTO 0)); 
end component;
component compardor
port(
A, B: in std_logic_vector(3 downto 0);
      AmaB, AmeB, AB: out std_logic);
end component;
begin
nueve(0)<=unologico;
nueve(1)<=not unologico;
nueve(2)<=not unologico;
nueve(3)<=unologico;
ocho(0)<=not unologico;
ocho(1)<=not unologico;
ocho(2)<=not unologico;
ocho(3)<=unologico;
siete(0)<=unologico;
siete(1)<= unologico;
siete(2)<= unologico;
siete(3)<=not unologico;
seis(0)<=not unologico;
seis(1)<= unologico;
seis(2)<= unologico;
seis(3)<= not unologico;
resta(0)<=not unologico;
resta(1)<=unologico;
resta(2)<=not unologico;
resta(3)<=not unologico;
A1:botones
port map(bo0,bo1,bo2,bo3,bo4,bo5,bo6,bo7,bo8,bo9,push0,A);
B1:botones
port map(bo0,bo1,bo2,bo3,bo4,bo5,bo6,bo7,bo8,bo9,push1,B);
U0:adder4b
PORT MAP(A,(push0 and(B(0) xor menos),push0 and(B(1)xor menos),push0 and(B(2)xor menos),push0 and(B(3)xor menos)),seg,CI,seg3(3));
Com:compardor
port map(seg,nueve,mag(0),mag(1),mag(2));
U1:adder4b
PORT MAP(seg,((resta(0)xor unologico),(resta(1)xor unologico),(resta(2)xor unologico),(resta(3)xor unologico)),seg2,CI,seg3(0));
M0:multi
port map(A(0),A(1),B(0),B(1),seg1);
bcd:bdc7
port map((((seg(0)and not mag(0))or (seg2(0)and mag(0))or ((seg1(0)and multiplicacion)and not(mas xor menos)))and not seg3(3))or ((seg3(3)and seg(0))) ,(((seg(1)and not mag(0))or (seg2(1)and mag(0))or ((seg1(1)and multiplicacion)and not(mas xor menos)))and not seg3(3)) or ((seg3(3)and not seg(1))) or ((seg3(3)and seg(0))),(((seg(2)and not mag(0))or(seg2(2)and mag(0))or ((seg1(2)and multiplicacion)and not(mas xor menos)))and not seg3(3))or ((seg3(3)and not seg(1))) or ((seg3(3)and seg(0))),(((seg(3)and not mag(0))or (seg2(3)and mag(0))or ((seg1(3) and multiplicacion)and not(mas xor menos)))and not seg3(3))or ((seg3(3)and seg(1))),Ax0,Bx0,C0,D0,E0,F0,G0);
bcd1:bdc7
port map(mag(0),not unologico,not unologico,not unologico,Ax1,Bx1,C1,D1,E1,F1,G1);
end Behavioral;
