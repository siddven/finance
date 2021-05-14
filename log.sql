-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description FROM crime_scene_reports WHERE street = "Chamberlin Street";
SELECT transcript FROM interviews WHERE transcript LIKE "%courthouse%" AND year = 2020 AND month = 7 AND day = 28;

--chamberlin street, July 28th 2020


SELECT * FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28;

SELECT * FROM people WHERE license_plate = "5P2BI95" OR license_plate = "94KL13X"
OR license_plate = "6P58WS2" OR license_plate = "4328GD8" OR license_plate = "G412CB7" OR license_plate = "L93JTIZ" OR license_plate = "322W7JE" 
OR license_plate = "0NTHK55" OR license_plate = "0NTHK55" OR license_plate = "1106N58";
SELECT * FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28;

221103 | Patrick | (725) 555-4692 | 2963008352 | 5P2BI95
243696 | Amber | (301) 555-4174 | 7526138472 | 6P58WS2
396669 | Elizabeth | (829) 555-5269 | 7049073643 | L93JTIZ
--398010 | Roger | (130) 555-0289 | 1695452385 | G412CB7
--449774 | Madison | (286) 555-6063 | 1988161715 | 1106N58
467400 | Danielle | (389) 555-5198 | 8496433585 | 4328GD8
--514354 | Russell | (770) 555-1861 | 3592750733 | 322W7JE
--560886 | Evelyn | (499) 555-9472 | 8294398571 | 0NTHK55
686048 | Ernest | (367) 555-5533 | 5773159633 | 94KL13X
SELECT * FROM phone_calls WHERE caller = "(130) 555-0289" AND year = 2020 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE caller = "(286) 555-6063" AND year = 2020 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE caller = "(389) 555-5198" AND year = 2020 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE caller = "(770) 555-1861" AND year = 2020 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE caller = "(499) 555-9472" AND year = 2020 AND month = 7 AND day = 28;
SELECT * FROM phone_calls WHERE caller = "(367) 555-5533" AND year = 2020 AND month = 7 AND day = 28;


246 | 28500762 | 2020 | 7 | 28 | Fifer Street | withdraw | 48
264 | 28296815 | 2020 | 7 | 28 | Fifer Street | withdraw | 20
266 | 76054385 | 2020 | 7 | 28 | Fifer Street | withdraw | 60
267 | 49610011 | 2020 | 7 | 28 | Fifer Street | withdraw | 50
269 | 16153065 | 2020 | 7 | 28 | Fifer Street | withdraw | 80
288 | 25506511 | 2020 | 7 | 28 | Fifer Street | withdraw | 20





