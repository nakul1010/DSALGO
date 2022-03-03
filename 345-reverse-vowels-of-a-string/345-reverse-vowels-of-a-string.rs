impl Solution 
{
    pub fn reverse_vowels(s: String) -> String 
    {
        // return s;
        let mut n = s.len();
        let mut vec:Vec<char> = s.chars().collect();
        let mut start:isize  = 0;
        let mut high:isize  = (s.len()-1) as isize ;
        
        while start<high
        {
            // println!("- start : {},  high : {}",start,high);
            while start<high && is_vowel(vec[start as usize])==false
            {
                start += 1;
            }
            while start<high && is_vowel(vec[high as usize])==false
            {
                high -= 1;
            }
            // println!("-- start : {},  high : {}",start,high);
            if is_vowel(vec[start as usize])==true && is_vowel(vec[high as usize])==true && start != high
            {
                // println!("start : {},  high : {}",start,high);
                vec.swap(start as usize, high as usize);
            }
            // println!("--- start : {},  high : {}",start,high);
            // if start==high
            // {
            //     break;
            // }
            start += 1;
            high -= 1;
            // println!("---- start : {},  high : {}",start,high);
        }
        
        return vec.into_iter().collect();
    }
}

    fn is_vowel(x : char) -> bool {
        x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'
    }