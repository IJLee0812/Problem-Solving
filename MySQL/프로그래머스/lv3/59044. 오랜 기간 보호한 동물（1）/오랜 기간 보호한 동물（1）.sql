SELECT NAME, DATETIME
from ANIMAL_INS
where ANIMAL_ID not in (select ANIMAL_ID
                        from ANIMAL_OUTS
                       )
order by DATETIME LIMIT 3;

-- 아직 입양을 못 갔음 : ANIMAL_OUTS 테이블에 없는 동물임. ANIMAL_INS 테이블에만 있는 동물들임. 이 동물들 3마리의 이름과 보호시작일을 조회. 결과는 보호 시작일 빠른 순으로 조회.