impl Solution {
    pub fn is_palindrome(x: i32) -> bool 
    {
        if x<0
        {
            return false;
        }
            
        
        let mut reverse_no:i32 = 0;
        
        let mut save_no:i32 = x;
        
        while save_no != 0 
        {
            reverse_no = (reverse_no*10) + (save_no%10);
            save_no = save_no / 10;
        }
        // println!("{}",reverse_no);
        if x == reverse_no
        {
            return true;
        }
            
        return false;
    }
}