impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) 
    {
        let mut n = s.len();
        let mut ch = 'a';
        // println!("n : {}",n);
        
        for i in 0..n/2
        {
            ch = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = ch;
        }
    }
}