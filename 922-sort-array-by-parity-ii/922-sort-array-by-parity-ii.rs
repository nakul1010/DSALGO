impl Solution {
    pub fn sort_array_by_parity_ii(arr: Vec<i32>) -> Vec<i32> 
    {
        let mut odd : Vec<i32> = vec![];
        let mut even : Vec<i32> = vec![];   
        let mut vec : Vec<i32> = vec![];
        // let mut odd = Vec::new();
        // let mut even : Vec::new();
        let mut n = arr.len();
        
        for i in arr.iter()
        {
            if i%2 == 0
            {
                even.push(*i);
            }
            else
            {
                odd.push(*i);
            }
        }
        
        
        println!("{}",even[0]);
        for i in 0..n
        {
            if i%2==0
            {
                vec.push(even[0]);
                even.drain(0..1);
            }
            else
            {
                
                vec.push(odd[0]);
                odd.drain(0..1);
            }
        }
        
        return vec;
    }
}