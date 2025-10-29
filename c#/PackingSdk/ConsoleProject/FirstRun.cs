using knest;
using System.Threading;
using System;
using Newtonsoft.Json;
using System.Runtime.InteropServices;

public class FirstRun {
    internal static string jsonString = "{\"version\":\"1\",\"data\":{\"param\":{\"material\":\"9横纹欧洲怡情多层\",\"thickness\":9.0,\"trimL\":3.0,\"trimR\":3.0,\"trimT\":3.0,\"trimB\":3.0,\"spacing\":6.0,\"binLength\":2440.0,\"binWidth\":1220.0,\"binCount\":1000000,\"loopCount\":2,\"baseCorner\":1,\"nestType\":3,\"enablePriority\":false,\"higherPriorityPlacedFront\":true,\"resultTimeOut\":6000,\"littleBoardLength\":230.0,\"littleBoardArea\":90000.0},\"parts\":[{\"code\":\"1557001007\",\"length\":383.0,\"width\":587.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":587.0},{\"x\":383.0,\"y\":587.0},{\"x\":383.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557001024\",\"length\":734.0,\"width\":587.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":587.0},{\"x\":734.0,\"y\":587.0},{\"x\":734.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557002007\",\"length\":237.0,\"width\":587.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":587.0},{\"x\":237.0,\"y\":587.0},{\"x\":237.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557003008\",\"length\":518.0,\"width\":587.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":587.0},{\"x\":518.0,\"y\":587.0},{\"x\":518.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557003016\",\"length\":574.0,\"width\":587.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":587.0},{\"x\":574.0,\"y\":587.0},{\"x\":574.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557004008\",\"length\":856.0,\"width\":367.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":367.0},{\"x\":856.0,\"y\":367.0},{\"x\":856.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557005013\",\"length\":969.0,\"width\":644.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":644.0},{\"x\":969.0,\"y\":644.0},{\"x\":969.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557005022\",\"length\":471.0,\"width\":644.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":644.0},{\"x\":471.0,\"y\":644.0},{\"x\":471.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557006010\",\"length\":774.0,\"width\":644.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":644.0},{\"x\":774.0,\"y\":644.0},{\"x\":774.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557006019\",\"length\":318.0,\"width\":644.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":644.0},{\"x\":318.0,\"y\":644.0},{\"x\":318.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007058\",\"length\":914.0,\"width\":413.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":413.0},{\"x\":914.0,\"y\":413.0},{\"x\":914.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":413.0}]},{\"code\":\"1557007059\",\"length\":1312.0,\"width\":413.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":413.0},{\"x\":1312.0,\"y\":413.0},{\"x\":1312.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":413.0}]},{\"code\":\"1557007060\",\"length\":852.0,\"width\":596.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":596.0},{\"x\":852.0,\"y\":596.0},{\"x\":852.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007061\",\"length\":440.0,\"width\":596.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":596.0},{\"x\":440.0,\"y\":596.0},{\"x\":440.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007062\",\"length\":861.0,\"width\":596.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":596.0},{\"x\":861.0,\"y\":596.0},{\"x\":861.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007063\",\"length\":1309.0,\"width\":310.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":310.0},{\"x\":1309.0,\"y\":310.0},{\"x\":1309.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007066\",\"length\":852.0,\"width\":310.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":310.0},{\"x\":852.0,\"y\":310.0},{\"x\":852.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007067\",\"length\":861.0,\"width\":614.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":614.0},{\"x\":861.0,\"y\":614.0},{\"x\":861.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007068\",\"length\":870.0,\"width\":614.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":614.0},{\"x\":870.0,\"y\":614.0},{\"x\":870.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007069\",\"length\":422.0,\"width\":614.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":614.0},{\"x\":422.0,\"y\":614.0},{\"x\":422.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007090\",\"length\":360.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":360.0,\"y\":274.0},{\"x\":360.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007098\",\"length\":369.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":369.0,\"y\":274.0},{\"x\":369.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007106\",\"length\":369.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":369.0,\"y\":274.0},{\"x\":369.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007114\",\"length\":369.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":369.0,\"y\":274.0},{\"x\":369.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557007122\",\"length\":360.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":360.0,\"y\":274.0},{\"x\":360.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557008028\",\"length\":715.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":715.0,\"y\":274.0},{\"x\":715.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557008036\",\"length\":715.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":715.0,\"y\":274.0},{\"x\":715.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557008044\",\"length\":715.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":715.0,\"y\":274.0},{\"x\":715.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557008052\",\"length\":715.0,\"width\":274.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":274.0},{\"x\":715.0,\"y\":274.0},{\"x\":715.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009053\",\"length\":787.0,\"width\":466.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":466.0},{\"x\":787.0,\"y\":466.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009054\",\"length\":787.0,\"width\":300.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":300.0},{\"x\":787.0,\"y\":300.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009055\",\"length\":787.0,\"width\":300.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":300.0},{\"x\":787.0,\"y\":300.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009056\",\"length\":787.0,\"width\":466.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":466.0},{\"x\":787.0,\"y\":466.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009057\",\"length\":824.0,\"width\":438.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":438.0},{\"x\":824.0,\"y\":438.0},{\"x\":824.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009058\",\"length\":824.0,\"width\":448.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":448.0},{\"x\":824.0,\"y\":448.0},{\"x\":824.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009059\",\"length\":824.0,\"width\":448.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":448.0},{\"x\":824.0,\"y\":448.0},{\"x\":824.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009060\",\"length\":824.0,\"width\":448.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":448.0},{\"x\":824.0,\"y\":448.0},{\"x\":824.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009061\",\"length\":824.0,\"width\":490.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":490.0},{\"x\":824.0,\"y\":490.0},{\"x\":824.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009062\",\"length\":796.0,\"width\":694.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":694.0},{\"x\":796.0,\"y\":694.0},{\"x\":796.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009063\",\"length\":787.0,\"width\":368.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":368.0},{\"x\":787.0,\"y\":368.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009064\",\"length\":787.0,\"width\":318.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":318.0},{\"x\":787.0,\"y\":318.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009065\",\"length\":787.0,\"width\":318.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":318.0},{\"x\":787.0,\"y\":318.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009066\",\"length\":787.0,\"width\":368.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":368.0},{\"x\":787.0,\"y\":368.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009067\",\"length\":787.0,\"width\":172.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":172.0},{\"x\":787.0,\"y\":172.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009068\",\"length\":796.0,\"width\":172.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":172.0},{\"x\":796.0,\"y\":172.0},{\"x\":796.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009069\",\"length\":787.0,\"width\":172.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":172.0},{\"x\":787.0,\"y\":172.0},{\"x\":787.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009093\",\"length\":323.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":323.0,\"y\":244.0},{\"x\":323.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009101\",\"length\":332.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":332.0,\"y\":244.0},{\"x\":332.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009109\",\"length\":332.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":332.0,\"y\":244.0},{\"x\":332.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009117\",\"length\":332.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":332.0,\"y\":244.0},{\"x\":332.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009125\",\"length\":332.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":332.0,\"y\":244.0},{\"x\":332.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557009133\",\"length\":323.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":323.0,\"y\":244.0},{\"x\":323.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557010023\",\"length\":1288.0,\"width\":245.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":245.0},{\"x\":1288.0,\"y\":245.0},{\"x\":1288.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557010026\",\"length\":865.0,\"width\":910.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":910.0},{\"x\":865.0,\"y\":910.0},{\"x\":865.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557010028\",\"length\":865.0,\"width\":1035.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":1035.0},{\"x\":865.0,\"y\":1035.0},{\"x\":865.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557010030\",\"length\":415.0,\"width\":1035.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":1035.0},{\"x\":415.0,\"y\":1035.0},{\"x\":415.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557010032\",\"length\":415.0,\"width\":910.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":910.0},{\"x\":415.0,\"y\":910.0},{\"x\":415.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557011008\",\"length\":426.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":426.0,\"y\":244.0},{\"x\":426.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557011016\",\"length\":426.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":426.0,\"y\":244.0},{\"x\":426.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557011024\",\"length\":426.0,\"width\":244.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":244.0},{\"x\":426.0,\"y\":244.0},{\"x\":426.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557012026\",\"length\":904.0,\"width\":706.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":706.0},{\"x\":904.0,\"y\":706.0},{\"x\":904.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557012027\",\"length\":888.0,\"width\":706.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":706.0},{\"x\":888.0,\"y\":706.0},{\"x\":888.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557012028\",\"length\":888.0,\"width\":706.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":706.0},{\"x\":888.0,\"y\":706.0},{\"x\":888.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013037\",\"length\":845.0,\"width\":349.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":349.0},{\"x\":845.0,\"y\":349.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013039\",\"length\":845.0,\"width\":360.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":360.0},{\"x\":845.0,\"y\":360.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013040\",\"length\":845.0,\"width\":349.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":349.0},{\"x\":845.0,\"y\":349.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013041\",\"length\":845.0,\"width\":340.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":340.0},{\"x\":845.0,\"y\":340.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013042\",\"length\":845.0,\"width\":340.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":340.0},{\"x\":845.0,\"y\":340.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013043\",\"length\":845.0,\"width\":360.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":360.0},{\"x\":845.0,\"y\":360.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013044\",\"length\":845.0,\"width\":437.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":437.0},{\"x\":845.0,\"y\":437.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013045\",\"length\":845.0,\"width\":437.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":437.0},{\"x\":845.0,\"y\":437.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013046\",\"length\":845.0,\"width\":438.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":438.0},{\"x\":845.0,\"y\":438.0},{\"x\":845.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013063\",\"length\":454.0,\"width\":682.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":682.0},{\"x\":454.0,\"y\":682.0},{\"x\":454.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557013064\",\"length\":365.0,\"width\":682.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":682.0},{\"x\":365.0,\"y\":682.0},{\"x\":365.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557014017\",\"length\":588.0,\"width\":374.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":374.0},{\"x\":588.0,\"y\":374.0},{\"x\":588.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557014025\",\"length\":588.0,\"width\":374.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":374.0},{\"x\":588.0,\"y\":374.0},{\"x\":588.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557015022\",\"length\":324.0,\"width\":828.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":828.0},{\"x\":324.0,\"y\":828.0},{\"x\":324.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":828.0}]},{\"code\":\"1557015023\",\"length\":324.0,\"width\":670.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":670.0},{\"x\":324.0,\"y\":670.0},{\"x\":324.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":670.0}]},{\"code\":\"1557015024\",\"length\":1496.0,\"width\":670.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":670.0},{\"x\":1496.0,\"y\":670.0},{\"x\":1496.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":670.0}]},{\"code\":\"1557015027\",\"length\":1874.0,\"width\":828.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":828.0},{\"x\":1874.0,\"y\":828.0},{\"x\":1874.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":828.0}]},{\"code\":\"1557015031\",\"length\":670.0,\"width\":370.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":370.0},{\"x\":670.0,\"y\":370.0},{\"x\":670.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557015082\",\"length\":333.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":333.0,\"y\":394.0},{\"x\":333.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557015090\",\"length\":333.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":333.0,\"y\":394.0},{\"x\":333.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557016024\",\"length\":727.0,\"width\":702.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":702.0},{\"x\":727.0,\"y\":702.0},{\"x\":727.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557016025\",\"length\":735.0,\"width\":702.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":702.0},{\"x\":735.0,\"y\":702.0},{\"x\":735.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557016026\",\"length\":1122.0,\"width\":702.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":702.0},{\"x\":1122.0,\"y\":702.0},{\"x\":1122.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557017014\",\"length\":740.0,\"width\":437.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":437.0},{\"x\":740.0,\"y\":437.0},{\"x\":740.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557017015\",\"length\":740.0,\"width\":427.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":427.0},{\"x\":740.0,\"y\":427.0},{\"x\":740.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557017016\",\"length\":740.0,\"width\":427.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":427.0},{\"x\":740.0,\"y\":427.0},{\"x\":740.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557017017\",\"length\":740.0,\"width\":679.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":679.0},{\"x\":740.0,\"y\":679.0},{\"x\":740.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557018014\",\"length\":519.0,\"width\":304.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":304.0},{\"x\":519.0,\"y\":304.0},{\"x\":519.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557018022\",\"length\":519.0,\"width\":304.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":304.0},{\"x\":519.0,\"y\":304.0},{\"x\":519.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019030\",\"length\":866.0,\"width\":430.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":430.0},{\"x\":866.0,\"y\":430.0},{\"x\":866.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019031\",\"length\":866.0,\"width\":405.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":405.0},{\"x\":866.0,\"y\":405.0},{\"x\":866.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019032\",\"length\":866.0,\"width\":405.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":405.0},{\"x\":866.0,\"y\":405.0},{\"x\":866.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019033\",\"length\":866.0,\"width\":420.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":420.0},{\"x\":866.0,\"y\":420.0},{\"x\":866.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019034\",\"length\":866.0,\"width\":704.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":704.0},{\"x\":866.0,\"y\":704.0},{\"x\":866.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019035\",\"length\":411.0,\"width\":704.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":704.0},{\"x\":411.0,\"y\":704.0},{\"x\":411.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019036\",\"length\":411.0,\"width\":420.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":420.0},{\"x\":411.0,\"y\":420.0},{\"x\":411.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019037\",\"length\":411.0,\"width\":405.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":405.0},{\"x\":411.0,\"y\":405.0},{\"x\":411.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019038\",\"length\":411.0,\"width\":405.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":405.0},{\"x\":411.0,\"y\":405.0},{\"x\":411.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557019039\",\"length\":411.0,\"width\":430.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":430.0},{\"x\":411.0,\"y\":430.0},{\"x\":411.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557020020\",\"length\":510.0,\"width\":761.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":761.0},{\"x\":510.0,\"y\":761.0},{\"x\":510.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":761.0}]},{\"code\":\"1557020021\",\"length\":510.0,\"width\":519.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":519.0},{\"x\":510.0,\"y\":519.0},{\"x\":510.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":519.0}]},{\"code\":\"1557020022\",\"length\":360.0,\"width\":519.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":519.0},{\"x\":360.0,\"y\":519.0},{\"x\":360.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":519.0}]},{\"code\":\"1557020023\",\"length\":370.0,\"width\":519.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":519.0},{\"x\":370.0,\"y\":519.0},{\"x\":370.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":519.0}]},{\"code\":\"1557020024\",\"length\":1132.0,\"width\":519.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":519.0},{\"x\":1132.0,\"y\":519.0},{\"x\":1132.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":519.0}]},{\"code\":\"1557020026\",\"length\":1878.0,\"width\":761.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":761.0},{\"x\":1878.0,\"y\":761.0},{\"x\":1878.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":761.0}]},{\"code\":\"1557020076\",\"length\":308.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":308.0,\"y\":394.0},{\"x\":308.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557020084\",\"length\":308.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":308.0,\"y\":394.0},{\"x\":308.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021045\",\"length\":856.0,\"width\":370.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":370.0},{\"x\":856.0,\"y\":370.0},{\"x\":856.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021046\",\"length\":856.0,\"width\":370.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":370.0},{\"x\":856.0,\"y\":370.0},{\"x\":856.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021047\",\"length\":510.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":510.0,\"y\":856.0},{\"x\":510.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021048\",\"length\":510.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":510.0,\"y\":856.0},{\"x\":510.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021049\",\"length\":510.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":510.0,\"y\":856.0},{\"x\":510.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021050\",\"length\":1366.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":1366.0,\"y\":856.0},{\"x\":1366.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021052\",\"length\":1366.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":1366.0,\"y\":856.0},{\"x\":1366.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021054\",\"length\":976.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":976.0,\"y\":856.0},{\"x\":976.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021056\",\"length\":760.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":760.0,\"y\":856.0},{\"x\":760.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021058\",\"length\":760.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":760.0,\"y\":856.0},{\"x\":760.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021060\",\"length\":1494.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":1494.0,\"y\":856.0},{\"x\":1494.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021062\",\"length\":1244.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":1244.0,\"y\":856.0},{\"x\":1244.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021064\",\"length\":1010.0,\"width\":856.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":856.0},{\"x\":1010.0,\"y\":856.0},{\"x\":1010.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":856.0}]},{\"code\":\"1557021066\",\"length\":1010.0,\"width\":783.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":783.0},{\"x\":1010.0,\"y\":783.0},{\"x\":1010.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":783.0}]},{\"code\":\"1557021068\",\"length\":1244.0,\"width\":783.0,\"quantity\":1,\"texture\":true,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":783.0},{\"x\":1244.0,\"y\":783.0},{\"x\":1244.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":783.0}]},{\"code\":\"1557021121\",\"length\":694.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":694.0,\"y\":394.0},{\"x\":694.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021130\",\"length\":694.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":694.0,\"y\":394.0},{\"x\":694.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021139\",\"length\":694.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":694.0,\"y\":394.0},{\"x\":694.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557021148\",\"length\":694.0,\"width\":394.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":394.0},{\"x\":694.0,\"y\":394.0},{\"x\":694.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557022013\",\"length\":332.0,\"width\":354.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":354.0},{\"x\":332.0,\"y\":354.0},{\"x\":332.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]},{\"code\":\"1557022021\",\"length\":380.0,\"width\":264.0,\"quantity\":1,\"texture\":false,\"priority\":0,\"outer\":[{\"x\":0.0,\"y\":0.0},{\"x\":0.0,\"y\":264.0},{\"x\":380.0,\"y\":264.0},{\"x\":380.0,\"y\":0.0},{\"x\":0.0,\"y\":0.0}]}]}}";

    //第一个运行例子（使用PackingSdk）
    public static void firstRun()
    {
        PackingSdk.NATIVE.setLogLevel(2);//当为5表示有错误时才打印日志，2表示调试打印

        //输入数据(算法参数与相关数据)
        NestInput nestInput = NestInput.CreateDefault();
        nestInput.data.algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        nestInput.data.algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        BinParameter bin = BinParameter.CreateDefault();//原材料大板参数
        bin.material = "加密多层贴白橡混拼";//
        bin.thickness = 9;
        bin.trimL = 4.0f;
        bin.trimR = 4.0f;
        bin.trimT = 4.0f;
        bin.trimB = 4.0f;
        bin.spacing = 8;
        bin.binLength = 2440.0;
        bin.binWidth = 1220.0;
        bin.binCount = 10000;
        bin.binValue = 0;
        nestInput.data.bins.Add(bin);
        NestPart part1 = NestPart.CreateDefault();
        part1.num = 1;
        part1.code = "C1";
        part1.length = 308.4;
        part1.width = 138.4;
        part1.quantity = 120;
        part1.texture = true;//有纹理要求，即不能旋转
        nestInput.data.parts.Add(part1);
        NestPart part2 = NestPart.CreateDefault();
        part2.num = 2;
        part2.code = "C2";
        part2.length = 308.4;
        part2.width = 138.4;
        part2.quantity = 1;
        part2.texture = true;
        nestInput.data.parts.Add(part2);
        NestPart part3 = NestPart.CreateDefault();
        part3.num = 3;
        part3.code = "C3";
        part3.length = 322.4;
        part3.width = 138.4;
        part3.quantity = 1;
        part3.texture = true;
        nestInput.data.parts.Add(part3);
        NestPart part4 = NestPart.CreateDefault();
        part4.num = 4;
        part4.code = "C4";
        part4.length = 322.4;
        part4.width = 138.4;
        part4.quantity = 1;
        part4.texture = true;
        nestInput.data.parts.Add(part4);
        //输入数据的版本
        nestInput.version = 1;
        // 序列化
        string json = JsonConvert.SerializeObject(nestInput, Formatting.Indented);

        //方式一 直接使用PackingSdk（dll接口）
        IntPtr sdk = PackingSdk.NATIVE.packingNew();
        PackingSdk.NATIVE.packingStart(sdk, json, true, null);
        while (PackingSdk.NATIVE.packingIsRunning(sdk))
        {
            Console.Write("..");
            Thread.Sleep(1000);
        }
        Console.WriteLine("finish!");
        //销毁
        PackingSdk.NATIVE.packingFree(sdk);
    }
    //第二个运行例子（使用封装后的PackingSdkWrapper）
    public static void secondRun()
    {
        //方式二 使用封装后的PackingSdkWrapper
        var sdkWrapper = new knest.PackingSdkWrapper();
        sdkWrapper.Start(jsonString);
        //模拟等待操作，目的是为了不让sdkWrapper被销毁
        while (sdkWrapper.IsRunning())
        {
            Console.Write("..");
            Thread.Sleep(1000);
        }
        Console.WriteLine("finish!");
    }
    //第三个运行例子，带回调的运行例子（使用PackingSdk-packingStart进行优化）
    public static void thirdRun()
    {
        // 定义回调函数
        PackingSdkCallbackVoid callback = (IntPtr sdkPtr, string data) =>
        {
            //Console.WriteLine($"回调接收到数据: {data}");
            // 尝试解析回调数据
            try
            {
                SolverOutput output = JsonConvert.DeserializeObject<SolverOutput>(data);
                Console.WriteLine($"算法状态: {output.solverState}");
                Console.WriteLine($"迭代次数: {output.numOfIteration}");
                Console.WriteLine($"利用率: {output.calUsage:P2}");
                Console.WriteLine($"进度: {output.calProgress}");
                Console.WriteLine("---");
                //转换jsonResult为NestOutput(注意当jsonResultAsFile为true时，output.jsonResult无法转换为NestOutput，因为此时output.jsonResult存放的是json文件路径)
                if (output.jsonResult is not null)
                {
                    string? jsonString = output.jsonResult?.ToString();
                    if (!string.IsNullOrEmpty(jsonString))
                    {
                        try
                        {
                            NestOutput nestOutput = JsonConvert.DeserializeObject<NestOutput>(jsonString);
                            Console.WriteLine($"排版图案数: {nestOutput.data.patterns.Count}");
                        }
                        catch (JsonException ex)
                        {
                            Console.WriteLine($"JSON反序列化(NestOutput)失败: {ex.Message}");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"解析回调数据出错: {ex.Message}");
            }
        };
        //输入数据(算法参数与相关数据)
        NestInput nestInput = NestInput.CreateDefault();
        nestInput.data.algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        nestInput.data.algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        BinParameter bin = BinParameter.CreateDefault();//原材料大板参数
        bin.material = "加密多层贴白橡混拼";//
        bin.thickness = 9;
        bin.trimL = 4.0f;
        bin.trimR = 4.0f;
        bin.trimT = 4.0f;
        bin.trimB = 4.0f;
        bin.spacing = 8;
        bin.binLength = 2440.0;
        bin.binWidth = 1220.0;
        bin.binCount = 10000;
        bin.binValue = 0;
        nestInput.data.bins.Add(bin);
        NestPart part1 = NestPart.CreateDefault();
        part1.num = 1;
        part1.code = "C1";
        part1.length = 308.4;
        part1.width = 138.4;
        part1.quantity = 120;
        part1.texture = true;//有纹理要求，即不能旋转
        nestInput.data.parts.Add(part1);
        NestPart part2 = NestPart.CreateDefault();
        part2.num = 2;
        part2.code = "C2";
        part2.length = 308.4;
        part2.width = 138.4;
        part2.quantity = 1;
        part2.texture = true;
        nestInput.data.parts.Add(part2);
        NestPart part3 = NestPart.CreateDefault();
        part3.num = 3;
        part3.code = "C3";
        part3.length = 322.4;
        part3.width = 138.4;
        part3.quantity = 1;
        part3.texture = true;
        nestInput.data.parts.Add(part3);
        NestPart part4 = NestPart.CreateDefault();
        part4.num = 4;
        part4.code = "C4";
        part4.length = 322.4;
        part4.width = 138.4;
        part4.quantity = 1;
        part4.texture = true;
        nestInput.data.parts.Add(part4);
        //输入数据的版本
        nestInput.version = 1;
        // 序列化
        string json = JsonConvert.SerializeObject(nestInput, Formatting.Indented);
        //方式一 直接使用PackingSdk（dll接口）
        IntPtr sdk = PackingSdk.NATIVE.packingNew();//创建PackingSdk实例
        PackingSdk.NATIVE.packingStart(sdk, json, true, callback);//开始排版优化
        //模拟等待
        while (PackingSdk.NATIVE.packingIsRunning(sdk))
        {
            Console.Write("..");
            Thread.Sleep(1000);
        }
        //销毁
        PackingSdk.NATIVE.packingFree(sdk);
        Console.WriteLine("finish!");
    }
    //第四个运行例子，带回调的运行例子（使用PackingSdk-doOptimization进行优化）
    public static void fourthRun()
    {
        // 定义回调函数
        PackingSdkCallback callback = (IntPtr sdkPtr, string data) =>
        {
            //Console.WriteLine($"回调接收到数据: {data}");
            // 尝试解析回调数据
            try
            {
                SolverOutput output = JsonConvert.DeserializeObject<SolverOutput>(data);
                Console.WriteLine($"算法状态: {output.solverState}");
                Console.WriteLine($"迭代次数: {output.numOfIteration}");
                Console.WriteLine($"利用率: {output.calUsage:P2}");
                Console.WriteLine($"进度: {output.calProgress}");
                Console.WriteLine("---");
                //转换jsonResult为NestOutput(注意当jsonResultAsFile为true时，output.jsonResult无法转换为NestOutput，因为此时output.jsonResult存放的是json文件路径)
                if (output.jsonResult != null)
                {
                    string? jsonString = output.jsonResult?.ToString();
                    if (!string.IsNullOrEmpty(jsonString))
                    {
                        try
                        {
                            NestOutput nestOutput = JsonConvert.DeserializeObject<NestOutput>(jsonString);
                            Console.WriteLine($"排版图案数: {nestOutput.data.patterns.Count}");
                        }
                        catch (JsonException ex)
                        {
                            Console.WriteLine($"JSON反序列化(NestOutput)失败: {ex.Message}");
                        }
                    }
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"解析回调数据出错: {ex.Message}");
            }
            return false; // 继续优化
        };
        //输入数据(算法参数与相关数据)
        NestInput nestInput = NestInput.CreateDefault();
        nestInput.data.algorithmParam.resultTimeOut = 10000;//当有优化结果后，等待10秒后再无优化结果变化，则算法停止运行
        nestInput.data.algorithmParam.jsonResultAsFile = false;//是否将优化结果输出为文件
        BinParameter bin = BinParameter.CreateDefault();//原材料大板参数
        bin.material = "加密多层贴白橡混拼";//
        bin.thickness = 9;
        bin.trimL = 4.0f;
        bin.trimR = 4.0f;
        bin.trimT = 4.0f;
        bin.trimB = 4.0f;
        bin.spacing = 8;
        bin.binLength = 2440.0;
        bin.binWidth = 1220.0;
        bin.binCount = 10000;
        bin.binValue = 0;
        nestInput.data.bins.Add(bin);
        NestPart part1 = NestPart.CreateDefault();
        part1.num = 1;
        part1.code = "C1";
        part1.length = 308.4;
        part1.width = 138.4;
        part1.quantity = 120;
        part1.texture = true;//有纹理要求，即不能旋转
        nestInput.data.parts.Add(part1);
        NestPart part2 = NestPart.CreateDefault();
        part2.num = 2;
        part2.code = "C2";
        part2.length = 308.4;
        part2.width = 138.4;
        part2.quantity = 1;
        part2.texture = true;
        nestInput.data.parts.Add(part2);
        NestPart part3 = NestPart.CreateDefault();
        part3.num = 3;
        part3.code = "C3";
        part3.length = 322.4;
        part3.width = 138.4;
        part3.quantity = 1;
        part3.texture = true;
        nestInput.data.parts.Add(part3);
        NestPart part4 = NestPart.CreateDefault();
        part4.num = 4;
        part4.code = "C4";
        part4.length = 322.4;
        part4.width = 138.4;
        part4.quantity = 1;
        part4.texture = true;
        nestInput.data.parts.Add(part4);
        //输入数据的版本
        nestInput.version = 1;
        // 序列化
        string json = JsonConvert.SerializeObject(nestInput, Formatting.Indented);
        //方式一 直接使用PackingSdk（dll接口）
        IntPtr sdk = PackingSdk.NATIVE.packingNew();
        IntPtr resultPtr = PackingSdk.NATIVE.doOptimization(sdk, json, true, callback);
        // 检查返回的指针是否为空
        if (resultPtr != IntPtr.Zero)
        {
            // 将C++返回的char*转换为C#字符串(此处必须将其转换为utf-8编码，否则在反序列化的时候会应乱码而失败)
            int length = 0;
            while (Marshal.ReadByte(resultPtr, length) != 0)
            {
                length++;
            }
            byte[] bytes = new byte[length];
            Marshal.Copy(resultPtr, bytes, 0, length);
            string result = System.Text.Encoding.UTF8.GetString(bytes);
            SolverOutput output = JsonConvert.DeserializeObject<SolverOutput>(result);
            //将jsonResult转换为NestOutput
            if (nestInput.data.algorithmParam.jsonResultAsFile == false && output.bestResultSheetCount > 0)
            {
                string? jsonString = output.jsonResult?.ToString();
                if (!string.IsNullOrEmpty(jsonString))
                {
                    try
                    {
                        NestOutput nestOutput = JsonConvert.DeserializeObject<NestOutput>(jsonString);
                        Console.WriteLine($"排版图案数: {nestOutput.data.patterns.Count}");
                    }
                    catch (JsonException ex)
                    {
                        Console.WriteLine($"JSON反序列化(NestOutput)失败: {ex.Message}");
                    }
                }
            }
        }
        //销毁
        PackingSdk.NATIVE.packingFree(sdk);
        Console.WriteLine("finish!");
    }
}