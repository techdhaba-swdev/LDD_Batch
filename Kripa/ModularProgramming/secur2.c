int user_id = 1000000000; // May overflow on 32-bit 
systemsuser_id++; // Could become negative due to overflowif 
(user_id > 100) { // Check might fail due to unexpected value// Grant access (potentially unintended)}
