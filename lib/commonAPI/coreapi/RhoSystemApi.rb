class System
   class << self
       alias_method :orig_get_property, :get_property
   end
   
   def self.get_property(prop_name)

       return screenWidth if prop_name == 'screen_width'
       return screenHeight if prop_name == 'screen_height'
       
       return realScreenHeight if prop_name == 'real_screen_width'
       return realScreenHeight if prop_name == 'real_screen_height'
       
       return ppiX if prop_name == 'ppi_x'
       return ppiY if prop_name == 'ppi_y'

       return localServerPort if prop_name == 'rhodes_port'
       return freeServerPort if prop_name == 'free_server_port'

       res = orig_get_property(prop_name)
    
       return true if res == 'true'
       return false if res == 'false'
       res
   end
end