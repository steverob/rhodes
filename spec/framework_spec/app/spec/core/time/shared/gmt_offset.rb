describe :time_gmt_offset, :shared => true do
  it "returns the offset in seconds between the timezone of time and UTC" do
    with_timezone("AST", 3) do
      Time.new.send(@method).should == 10800
    end
  end
if System.get_property('platform') != 'APPLE'
  it "returns the correct offset for US Eastern time zone around daylight savings time change" do
    with_timezone("EST5EDT") do
      Time.local(2010,3,14,1,59,59).send(@method).should == -5*60*60
      if System.get_property('platform') != 'WINDOWS' && System.get_property('platform') != 'WINDOWS_DESKTOP'
        Time.local(2010,3,14,2,0,0).send(@method).should == -4*60*60
      end  
    end
  end
end
  #it "returns the correct offset for Hawaii around daylight savings time change" do
  #  with_timezone("Pacific/Honolulu") do
  #    Time.local(2010,3,14,1,59,59).send(@method).should == -10*60*60
  #    Time.local(2010,3,14,2,0,0).send(@method).should == -10*60*60
  #  end
  #end

  #it "returns the correct offset for New Zealand around daylight savings time change" do
  #  with_timezone("Pacific/Auckland") do
  #    Time.local(2010,4,4,1,59,59).send(@method).should == 13*60*60
  #    Time.local(2010,4,4,3,0,0).send(@method).should == 12*60*60
  #  end
  #end
end
