select ID, FISH_NAME, LENGTH
from FISH_INFO join FISH_NAME_INFO using (FISH_TYPE)
where FISH_TYPE in (select FISH_TYPE
                from FISH_INFO
                group by FISH_TYPE
                having LENGTH = max(LENGTH))
order by ID asc;