select OUTS.ANIMAL_ID, OUTS.NAME
from ANIMAL_INS as INS right outer join ANIMAL_OUTS as OUTS using (ANIMAL_ID)
where INS.ANIMAL_ID is null
order by OUTS.ANIMAL_ID; -- NAME이 두 테이블에서 모두 nullable하므로, ID로 JOIN해야함