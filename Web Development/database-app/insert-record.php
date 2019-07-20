<?php

    // phpinfo();
    error_reporting(E_ALL);
    ini_set("display_errors", "1");

?>

<!doctype html>
<html>
    <head>
        <meta charset="utf-8">
        <meta http-equiv="content-type" content="text/html" charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">

        <title>MySQL Connect : Insert new user record</title>

        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css" integrity="sha384-ggOyR0iXCbMQv3Xipma34MD+dH/1fQ784/j6cY/iJTQUOhcWr7x9JvoRxT2MZw1T" crossorigin="anonymous">
    </head>
    
    <body>

        <div class="bg-light">
            <div class="container">
                <!-- Start of navigation bar  -->
                <div class="navbar navbar-expand-lg navbar-light">
                        
                    <a href="" class="navbar-brand">My Records</a>

                    <button type="button" class="navbar-toggler" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
                        <span class="navbar-toggler-icon"></span>
                    </button>

                    <div class="navbar-collapse collapse ">
                        <ul class="navbar-nav mr-auto">
                            <li class="nav-item"><a href="view-record.php" class="nav-link">View Records</a></li>
                            <li class="nav-item active"><a href="insert-record.php" class="nav-link">Insert Records</a></li>
                        </ul>
                    </div> <!-- Collapsed area for navbar while expanding -->

                </div> <!-- End of navbar -->
            </div>
        </div>

        <!-- Part to build connection to remote database -->
        <div class="container">
            
            <?php

                // Establish the linking to db, open it and return the link (or pointer)
                $mysql = mysqli_connect("local", "vincent", "+-*/1234", "table");

                // Case if there is error with the connection to database 
                if(!$mysql){
                    echo "Error : Unable to connect to MySQL <br>";
                    echo "Debugging Errno : " . mysqli_connect_errno() . "<br>";
                    echo "Debugging Error : " . mysqli_connect_error() . "<br>";
                    
                    exit();
                }

                // Else
                // echo "Success! Connection to MySQL remote database";
                // echo "Connection Information : " . mysqli_get_host_info($mysql) ; 

            ?>
        </div>

        <!-- Form Container -->
        <div class="container mt-3">

            <h1>Insert New Data Entry</h1>

            <!-- Form Structure -->
            <form name="myForm" class="form-horizontal needs-validation" role="form" method="POST" action="#">
                
                <!-- Form Data Validation by using PHP -->
                <?php
                    
                    function valid_input($data){
                        $data = trim($data);
                        $data = stripslashes($data);
                        $data = htmlspecialchars($data);
                        return $data;
                    }

                    /**
                     * Function to validate a given username
                     */
                    function validate_name($name){
                        if(!preg_match("/^[a-zA-Z ]*$/", $name))
                            return false;
                        return true;
                    }

                    // Declare variables for error displaying
                    $firstName = $lastName = $emailAddress = $password = "";
                    $firstnameErr = $lastnameErr = $emailAddressErr = $pwdErr = "";

                    // Case if the submit button is clicked : it returned as an associative array
                    if(isset($_POST["submit"])) {

                        if(!empty($_POST["firstName"])){

                            $firstName = valid_input($_POST["firstName"]);

                            // Case if the filtered variable has no data
                            if(!validate_name($firstName) || $firstName == "")
                                $firstnameErr .= "Only letters and whitespace allowed for a valid first name<br>";

                        }

                        if(!empty($_POST["lastName"])){

                            $lastName = valid_input($_POST["lastName"]);

                            // Case if the filtered variable has no data
                            if(!validate_name($lastName) || $lastName == "")
                                $lastnameErr .= "Only letters and whitespace allowed for a valid last name<br>";

                        }

                        if(!empty($_POST["emailAddress"])){
                            $emailAddress = filter_var($_POST["emailAddress"], FILTER_SANITIZE_EMAIL);

                            if(!filter_var($emailAddress, FILTER_VALIDATE_EMAIL))
                                $emailAddressErr .= "Please enter a valid email address <br>";
                        }

                        if(!empty($_POST["password"])){
                            $pwd = valid_input($_POST["password"]);

                            // Password Validation from link : https://stackoverflow.com/questions/22544250/php-password-validation#22544286
                            if(strlen($_POST["password"]) <= '8')
                                $pwdErr = "Your password must contain at LEAST 8 characters<br>";
                            elseif(!preg_match("#[0-9]+#", $pwd))
                                $pwdErr = "Your password must contain at LEAST A DIGIT<br>";
                            elseif(!preg_match("#[A-Z]+#", $pwd))
                                $pwdErr = "Your password must contain at LEAST AN UPPERCASE ALPHABET<br>";
                            elseif(!preg_match("#[a-z]+#", $pwd))
                                $pwdErr = "Your password must contain at LEAST A LOWERCASE ALPHABET<br>";
                            else{
                                // Else the user password meets all the criteria above and start hashing        
                                // PHP Built-in Hashing Algorithm to do one-way encryption of given password
                                $pwd_hash = password_hash($pwd, PASSWORD_DEFAULT);

                                // echo "Original Password : $pwd <br>";
                                // echo "Hashed Password : $pwd_hash <br>";
                            }
                        }
                        
                    
                        // If any of the input is having validation error
                        if($firstnameErr || $lastnameErr || $emailAddressErr || $pwdErr){    

                ?>

                    <!-- Display this alert if there is at least one error in the form input -->
                    <div class="col-sm-10">
                        <div class="alert alert-danger">
                            <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
                            <strong>Error!</strong> Errors are found in the form bellow : <br>
                        </div>
                    </div>

                <?php

                        }else{

                            // No Error in new data entry submission
                            $firstName = $_POST["firstName"];
                            $lastName = $_POST["lastName"];
                            $emailAddress = $_POST["emailAddress"];
                            $password = $_POST["password"];

                            // SQL query to insert a new data entry into the given table
                            $str_query = "INSERT INTO user (firstName, lastName, emailAddress, password) VALUES ('$firstName', '$lastName' , '$emailAddress', '$password')";
                            $query = mysqli_query($mysql, $str_query);

                            if(!$query){

                                // Unsuccessful SQL query submission
                                // Display query-related errors
                                echo "Error ! ". mysqli_error($mysql) . "<br>";
                            }else{
                ?>
                    <!-- Display this alert if the form is validated and successfully sent -->
                    <div class="col-sm-10">
                        <div class="alert alert-success">
                                <a href="#" class="close" data-dismiss="alert" aria-label="close">&times;</a>
                                <strong>Success!</strong> The new data entry has been inserted !<br>
                                <a href="view-record.php">Click here</a> to view all the records
                        </div>
                    </div>
                <?php
                            }

                        } // Close for form test   

                        mysqli_close($mysql);
                    }
    
                ?>

                <!-- Group for inserting firstName -->
                <div class="form-group">
                    <label for="firstName" class="col-sm-8">Firstname<span class="text-danger">*</span> :</label> 

                    <!-- Container for text input -->
                    <div class="col-sm-8">
                        <input type="text" name="firstName" class="form-control" placeholder="Enter your first name here" value="<?php if($firstName){ echo $firstName; } ?>" required>
                        <span class="text-danger small"><?php echo $firstnameErr; ?></span>
                    </div>
                </div>

                <!-- Group for inserting lastName -->
                <div class="form-group">
                    <label for="lastName" class="col-sm-8">Lastname<span class="text-danger">*</span> :</label> 

                    <!-- Container for text input -->
                    <div class="col-sm-8">
                        <input type="text" name="lastName" class="form-control" placeholder="Enter your last name here" value="<?php if($lastName){ echo $lastName; } ?>" required>
                        <span class="text-danger small"><?php echo $lastnameErr; ?></span>
                    </div>
                </div>

                <!-- Group for inserting email address -->
                <div class="form-group">
                    <label for="emailAddress" class="col-sm-8">Email Address<span class="text-danger">*</span> :</label>

                    <div class="col-sm-8">
                        <input type="email" name="emailAddress" class="form-control" placeholder="eg. example@email.com" value="<?php if($emailAddress){ echo $emailAddress; } ?>" required>
                        <span class="text-danger small"><?php echo $emailAddressErr; ?></span>
                    </div>
                </div>

                <!-- Group for inserting password -->
                <div class="form-group">
                    <label for="password" class="col-sm-8">Password<span class="text-danger">*</span> :</label>

                    <div class="col-sm-8">
                        <input type="password" name="password" class="form-control" placeholder="Enter your password here" value="<?php if($password){ echo $password; } ?>" required>
                        <span class="text-danger small"><?php echo $pwdErr; ?></span>
                    </div>
                </div>
                
                <!-- Group for submit button -->
                <div class="form-group">
                    <div class="col-sm-8">
                        <!-- Expected to do error checking when this button is clicked -->
                        <button type="submit" name="submit" class="btn btn-primary">Submit Form</button>
                    </div>
                </div>
            </form>
        </div>

        <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
        <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
        <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
    </body>
</html>